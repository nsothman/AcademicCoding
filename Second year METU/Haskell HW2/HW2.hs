module HW2 (
    parse, -- reexport for easy terminal use
    foldAndPropagateConstants,
    assignCommonSubexprs,
    reducePoly
) where

import Expression
import Parser
import Data.List
import Data.Tuple

-- Do not change the module definition and imports above! Feel free
-- to modify the parser, but please remember that it is just a helper
-- module and is not related to your grade. You should only submit
-- this file. Feel free to import other modules, especially Data.List!

inList :: String -> [String] -> Int -> Int
inList _ y z | z == length y = -2
inList x y z = if x == y!!z then z else inList x y (z+1)

exprType :: ExprV -> String
exprType (Leaf (Constant x)) = "const"
exprType (BinaryOperation Times (x) (y)) = "times"
exprType (BinaryOperation Plus (x) (y)) = "plus"
exprType (UnaryOperation Minus x) = "minus"
exprType (Leaf (Variable x)) = "var"

makeStrList :: [(String, ExprV)] -> [String]
makeStrList [] = []
makeStrList x = if exprType (snd (x!!0)) == "const" then [fst (x!!0)] ++ makeStrList (drop 1 x) else []
makeIntList :: [(String, ExprV)] -> [Int]
makeIntList [] = []
makeIntList x = if exprType (snd (x!!0)) == "const" then [evaluateConst (snd (x!!0))] ++ makeIntList (drop 1 x) else []

replaceVariables :: ExprV -> [String] -> [Int] -> ExprV
replaceVariables (Leaf (Constant x)) _ _ = (Leaf (Constant x))
replaceVariables (Leaf (Variable x)) y z = if (inList x y 0 /= -2) then (Leaf (Constant (z!!(inList x y 0)))) else (Leaf (Variable x))
replaceVariables (UnaryOperation Minus x) y z= (UnaryOperation Minus (replaceVariables x y z))
replaceVariables (BinaryOperation Plus (x) (y)) z w = (BinaryOperation Plus (replaceVariables x z w) (replaceVariables y z w))
replaceVariables (BinaryOperation Times (x) (y)) z w = (BinaryOperation Times (replaceVariables x z w) (replaceVariables y z w))

evaluateConst :: ExprV -> Int
evaluateConst (Leaf (Constant x)) = x
evaluateConst (UnaryOperation Minus x) = (- (evaluateConst x))
evaluateConst (BinaryOperation Plus (x) (y)) = evaluateConst x + evaluateConst y
evaluateConst (BinaryOperation Times (x) (y)) = evaluateConst x  * evaluateConst y

evaluate :: ExprV -> ExprV
evaluate (Leaf (Constant x)) = (Leaf (Constant x))
evaluate (Leaf (Variable x)) = (Leaf (Variable x))
evaluate (UnaryOperation Minus x) = if exprType x == "const" || exprType x == "var" then (UnaryOperation Minus x) else
                                    if (exprType x == "minus" && varConstCheck x) then (Leaf (Constant (evaluateConst x))) else 
                                    if (exprType x == "minus" && (not(varConstCheck x))) then (UnaryOperation Minus (evaluate x)) else
                                    if (exprType x == "plus" || exprType x == "times") && (varConstCheck x) then (UnaryOperation Minus (Leaf (Constant (evaluateConst x)))) else
                                    if (exprType x == "plus" || exprType x == "times") && not(varConstCheck x) then (UnaryOperation Minus (evaluate x)) else (UnaryOperation Minus x)
evaluate (BinaryOperation Plus (x) (y)) = if varConstCheck (BinaryOperation Plus (x) (y)) then (Leaf (Constant (evaluateConst (BinaryOperation Plus (x) (y))))) else 
                                    if not(varConstCheck (y)) && varConstCheck (x) then (BinaryOperation Plus (Leaf (Constant (evaluateConst x))) (evaluate (y))) else
                                    if not(varConstCheck (x)) && varConstCheck (y) then (BinaryOperation Plus (evaluate (x)) (Leaf (Constant (evaluateConst y)))) else (BinaryOperation Plus (evaluate (x)) (evaluate (y)))
evaluate (BinaryOperation Times (x) (y)) = if varConstCheck (BinaryOperation Times (x) (y)) then (Leaf (Constant (evaluateConst (BinaryOperation Times (x) (y))))) else 
                                    if not(varConstCheck (BinaryOperation Times (x) (y))) && varConstCheck (x) then (BinaryOperation Times (Leaf (Constant (evaluateConst x))) (evaluate (y))) else
                                    if not(varConstCheck (BinaryOperation Times (x) (y))) && varConstCheck (y) then (BinaryOperation Times (evaluate (x)) (Leaf (Constant (evaluateConst y)))) else (BinaryOperation Times (evaluate (x)) (evaluate (y)))

varConstCheck :: ExprV -> Bool
varConstCheck (Leaf (Constant x)) = True
varConstCheck (Leaf (Variable x)) = False
varConstCheck (BinaryOperation Plus (x) (y)) = if exprType x == "const" && exprType y == "const" then True else
                                    if (exprType x == "var" || exprType y == "var") then False else
                                    if exprType x == "const" && exprType y == "plus" then varConstCheck y else
                                    if exprType x == "plus" && exprType y == "const" then varConstCheck x else (varConstCheck x && varConstCheck y)
varConstCheck (BinaryOperation Times (x) (y)) = if exprType x == "const" && exprType y == "const" then True else
                                    if (exprType x == "var" || exprType y == "var") then False else
                                    if exprType x == "const" && exprType y == "times" then varConstCheck y else
                                    if exprType x == "times" && exprType y == "const" then varConstCheck y else (varConstCheck x && varConstCheck y)
varConstCheck (UnaryOperation Minus x) = if exprType x == "const" then True else if exprType x == "var" then False else varConstCheck x

fapcHelper :: [(String, ExprV)] -> [(String, ExprV)] -> [(String, ExprV)]
fapcHelper [] _ = []
fapcHelper x y = [((fst (x!!0)), evaluate (replaceVariables (snd (x!!0)) (makeStrList y) (makeIntList y)))] ++ (fapcHelper (drop 1 x) ([((fst (x!!0)), evaluate (replaceVariables (snd (x!!0)) (makeStrList y) (makeIntList y)))]  ++ (drop 1 x)))

foldAndPropagateConstants :: [(String, ExprV)] -> [(String, ExprV)]
foldAndPropagateConstants [] = []
foldAndPropagateConstants x | (length x == 1) = [((fst (x!!0)), (evaluate (replaceVariables (snd (x!!0)) (makeStrList x) (makeIntList x))))]
foldAndPropagateConstants x = fapcHelper x x

----------------------------------------------------------------------------------------------------

inListExpr :: ExprV -> [(String, ExprV)] -> Int -> Int
inListExpr _ y z | z == length y = -2
inListExpr x y z = if x == (snd (y!!z)) then z else inListExpr x y (z+1)

makeExprList :: ExprV -> [ExprV]
makeExprList (Leaf (Constant x)) = []
makeExprList (Leaf (Variable x)) = []
makeExprList (UnaryOperation Minus x) = if (exprType x == "plus" || exprType x == "times" || exprType x == "minus") 
                                    then [UnaryOperation Minus ((makeExprList x)!!0)] else [(UnaryOperation Minus x)]
makeExprList (BinaryOperation Plus (x) (y)) = if (exprType x == "const" || exprType x == "var" || (exprType x == "minus" && makeExprList x == [])) && (exprType y == "const" || exprType y == "var" || (exprType y == "minus" && makeExprList y == []))
                                    then [(BinaryOperation Plus (x) (y))]
                                    else (makeExprList x) ++ (makeExprList y)
makeExprList (BinaryOperation Times (x) (y)) = if (exprType x == "const" || exprType x == "var" || (exprType x == "minus" && makeExprList x == [])) && (exprType y == "const" || exprType y == "var" || (exprType y == "minus" && makeExprList y == []))
                                    then [(BinaryOperation Times (x) (y))] 
                                    else (makeExprList x) ++ (makeExprList y)

keepDup :: [ExprV] -> [ExprV]
keepDup [] = []
keepDup x = if (exprInList (x!!0) (drop 1 x) 0) /= -2 
    then [x!!0] ++ keepDup (drop 1 ((take (exprInList (x!!0) (drop 1 x) 0) x) ++ (drop ((exprInList (x!!0) (drop 1 x) 0)+1) x)))
    else keepDup (drop 1 x)
exprInList :: ExprV -> [ExprV] -> Int -> Int
exprInList _ y z | z == length y = -2
exprInList x y z = if x == y!!z then z else exprInList x y (z+1)

makeListFinal :: [ExprV] -> Int -> [(String, ExprV)]
makeListFinal [] _ = []
makeListFinal x z = [(("$" ++ show z), (head x))] ++ makeListFinal (tail x) (z+1)

makeList :: ExprV -> Int -> [(String, ExprV)]
makeList x z = if x == updateExprLoop x (makeListFinal (keepDup (makeExprList x)) z) (length (makeListFinal (keepDup (makeExprList x)) z))
            then (makeListFinal (keepDup (makeExprList x)) z) else (makeListFinal (keepDup (makeExprList x)) z) ++ (makeListFinal (keepDup (makeExprList (updateExprLoop x (makeListFinal (keepDup (makeExprList x)) z) (length (makeListFinal (keepDup (makeExprList x)) z))))) (z+1))

updateExpr :: ExprV -> [(String, ExprV)] -> ExprV
updateExpr x [] = x
updateExpr (Leaf (Constant x)) _ = (Leaf (Constant x))
updateExpr (Leaf (Variable x)) _ = (Leaf (Variable x))
updateExpr (UnaryOperation Minus x) y = if (inListExpr (UnaryOperation Minus x) y 0) /= -2 
                                        then (Leaf (Variable (fst (y!!(inListExpr (UnaryOperation Minus x) y 0)))))
                                        else (UnaryOperation Minus x)
updateExpr (BinaryOperation Plus (x) (y)) z = if (inListExpr (BinaryOperation Plus (x) (y)) z 0) /= -2 
                                            then (Leaf (Variable (fst (z!!(inListExpr (BinaryOperation Plus (x) (y)) z 0)))))
                                            else (BinaryOperation Plus (updateExpr x z) (updateExpr y z))
updateExpr (BinaryOperation Times (x) (y)) z = if (inListExpr (BinaryOperation Times (x) (y)) z 0) /= -2 
                                            then (Leaf (Variable (fst (z!!(inListExpr (BinaryOperation Times (x) (y)) z 0)))))
                                            else (BinaryOperation Times (updateExpr x z) (updateExpr y z))
updateExprLoop :: ExprV -> [(String, ExprV)] -> Int -> ExprV
updateExprLoop x _ 0 = x
updateExprLoop x y z = updateExprLoop (updateExpr x y) y (z-1)

assignCommonSubexprs :: ExprV -> ([(String, ExprV)], ExprV)
assignCommonSubexprs x = ((makeList x 0), (updateExprLoop x (makeList x 0) (length (makeList x 0))))

----------------------------------------------------------------------------------------------------

mulTuple :: [(Int, Int)] -> [(Int, Int)] -> Int -> [(Int, Int)] 
mulTuple _ [] _ = []
mulTuple x y z | z == (length x) = []
mulTuple x y z = ([(((fst (x!!z)) + (fst (y!!0))), ((snd (x!!z)) * (snd (y!!0))))] ++ (tupleMult x (tail y) z) ++ (mulTuple x y (z+1)))
tupleMult :: [(Int, Int)] -> [(Int, Int)] -> Int -> [(Int, Int)] 
tupleMult _ [] _ = []
tupleMult x y z | z == (length x) = []
tupleMult x y z = ([(((fst (x!!z)) + (fst (y!!0))), ((snd (x!!z)) * (snd (y!!0))))] ++ (tupleMult x (tail y) z))
tupleAdd ::  [(Int, Int)] -> [(Int, Int)] -> [(Int, Int)]
tupleAdd [] _ = []
tupleAdd x [] = x
tupleAdd x y = if (indInList (fst (x!!0)) y 0) /= -2 
            then (tupleAdd ([((fst (x!!0)), (snd (x!!0)) + (snd (y!!(indInList (fst (x!!0)) y 0))))] ++ ((take (indInList (fst (x!!0)) y 0) y) ++ (drop ((indInList (fst (x!!0)) y 0)+1) y)))) ((take (indInList (fst (x!!0)) y 0) y) ++ (drop ((indInList (fst (x!!0)) y 0)+1) y)) 
            else ([(x!!0)] ++ (tupleAdd (tail x) (tail y)))
indInList :: Int -> [(Int, Int)] -> Int -> Int
indInList _ y z | z == length y = -2
indInList x y z = if x == (fst (y!!z)) then z else indInList x y (z+1)

makeIndCoList :: ExprV -> [(Int, Int)]
makeIndCoList x | (exprType x == "const") = [(0, (evaluateConst x))]
makeIndCoList x | (exprType x == "var") = [(1, 1)]
makeIndCoList (UnaryOperation Minus x) = if exprType x == "var" then [(1, -1)] 
                                            else if exprType x == "const" then [(0, -(evaluateConst x))]
                                            else (mulTuple (makeIndCoList x) [(0,-1)] 0)
makeIndCoList (BinaryOperation Times (x) (y)) = if ((exprType x == "var") && (exprType y == "const")) then [(1, (evaluateConst y))]
                                            else if ((exprType y == "var") && (exprType x == "const")) then [(1, (evaluateConst x))]
                                            else if ((exprType y == "const") && (exprType x == "const")) then [(0, ((evaluateConst x) * (evaluateConst y)))]
                                            else if ((exprType x == "var") && (exprType y == "var")) then [(2, 1)]
                                            else sort (tupleAdd (mulTuple (makeIndCoList x) (makeIndCoList y) 0) (tail (mulTuple (makeIndCoList x) (makeIndCoList y) 0)))
makeIndCoList (BinaryOperation Plus (x) (y)) = sort (tupleAdd ((makeIndCoList x) ++ (makeIndCoList y)) (tail ((makeIndCoList x) ++ (makeIndCoList y))))
removeZeroCo :: [(Int, Int)] -> [(Int, Int)]
removeZeroCo [] = []
removeZeroCo x = if (snd (head x)) == 0 then removeZeroCo (tail x) else [(head x)] ++ removeZeroCo (tail x)

identifyVar :: ExprV -> String
identifyVar (Leaf (Constant x)) = ""
identifyVar (Leaf (Variable x)) = x
identifyVar (UnaryOperation Minus x) = identifyVar x
identifyVar (BinaryOperation Plus (x) (y)) = if (identifyVar x) /= (identifyVar y) then ((identifyVar x) ++ (identifyVar y)) else (identifyVar x)
identifyVar (BinaryOperation Times (x) (y)) = if (identifyVar x) /= (identifyVar y) then ((identifyVar x) ++ (identifyVar y)) else (identifyVar x)

timesFromTuple :: (Int, Int) -> Int -> String -> ExprV
timesFromTuple x z y = if (z == 0) then (Leaf (Constant (snd x)))
                    else if (z == 1) && ((snd x) == 1) then (Leaf (Variable y))
                    else if (z == 1) && ((snd x) == -1) then (UnaryOperation Minus (Leaf (Variable y)))
                    else if (z == 1) && ((snd x) > 1) then (BinaryOperation Times (Leaf (Constant (snd x))) (Leaf (Variable y)))
                    else (BinaryOperation Times (timesFromTuple x (z-1) y) (Leaf (Variable y)))

exprFromList :: [(Int, Int)] -> String -> ExprV
exprFromList [] _ = Leaf (Constant 0)
exprFromList x y = if (length x == 1) then timesFromTuple (head x) (fst (head x)) y
                    else if (length x == 2) then (BinaryOperation Plus (timesFromTuple (x!!0) (fst (x!!0)) y) (timesFromTuple (x!!1) (fst (x!!1)) y))
                    else (BinaryOperation Plus (exprFromList (take 2 x) y) (exprFromList (drop 2 x) y))

reducePoly :: ExprV -> ExprV
reducePoly x = exprFromList (removeZeroCo (makeIndCoList x)) (identifyVar x)

-- an extra dummy variable, so as to not crash the GUI
notImpl :: ExprV
notImpl = Leaf $ Variable "Not Implemented"


evalDeriv :: [(String, Int)] -> String -> ExprV -> Int
evalDeriv _ _ (Leaf (Constant x)) = 0
evalDeriv y z (Leaf (Variable x)) = if x == z then 1  else 0
evalDeriv y z (UnaryOperation Minus x) = - (evalDeriv y z x)
evalDeriv z w (BinaryOperation Plus (x) (y)) = (evalDeriv z w x) + (evalDeriv z w y)
evalDeriv z w (BinaryOperation Times (x) (y)) = (evalExpr z x) * (evalDeriv z w y) + (evalExpr z y) * (evalDeriv z w x)
evalExpr :: [(String, Int)] -> ExprV -> Int
evalExpr _ (Leaf (Constant x)) = x
evalExpr y (Leaf (Variable x))= if (fst (head y) == x) then (snd (head y)) else (evalExpr (tail y) (Leaf (Variable x)))
evalExpr y (UnaryOperation Minus x) = -(evalExpr y x)
evalExpr z (BinaryOperation Plus (x) (y)) = (evalExpr z x) + (evalExpr z y)
evalExpr z (BinaryOperation Times (x) (y)) = (evalExpr z x) * (evalExpr z y)
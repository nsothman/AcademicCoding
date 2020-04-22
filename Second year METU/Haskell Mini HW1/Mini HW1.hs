module Mini1 (
    gridMap,
    gridMapIf,
    evalExpr,
    getVars,
    evalDeriv,
    parse -- reexported to allow use
    ) where

import Expression
import Parser
import Data.List

-- Do not modify the module declaration and imports above!
-- Also do not change the function signatures and do not
-- remove the dummy implementations of the functions if
-- you want your code to compile.

-- Feel free to import anything else here

-- gridMap (20 points), map function over grid elements
gridMap :: (a -> b) -> [[a]] -> [[b]]
gridMap _ [] = []
gridMap x y = [(map x (head y))] ++ (gridMap x (tail y))

-- gridMapIf (20 points), map functions over grid elements 
-- that satisfy the predicate provided as the first arg.
gridMapIfHelp :: (a -> Bool) -> (a -> a) -> [a] -> [a]
gridMapIfHelp _ _ [] = []
gridMapIfHelp x y z = if (x (head z)) then [y (head z)] ++ (gridMapIfHelp x y (tail z)) else [(head z)] ++ (gridMapIfHelp x y (tail z))

gridMapIf :: (a -> Bool) -> (a -> a) -> [[a]] -> [[a]]
gridMapIf _ _ [] = []
gridMapIf x y z = [(gridMapIfHelp x y (head z))] ++ (gridMapIf x y (tail z))

-- evalExpr (20 points), evaluate the expression by
-- substituting (var, value) pairs given in the first arg.
evalExpr :: [(String, Int)] -> ExprV -> Int
evalExpr _ (Leaf (Constant x)) = x
evalExpr y (Leaf (Variable x))= if (fst (head y) == x) then (snd (head y)) else (evalExpr (tail y) (Leaf (Variable x)))
evalExpr y (UnaryOperation Minus x) = -(evalExpr y x)
evalExpr z (BinaryOperation Plus (x) (y)) = (evalExpr z x) + (evalExpr z y)
evalExpr z (BinaryOperation Times (x) (y)) = (evalExpr z x) * (evalExpr z y)

-- getVars (20 points), return the variables contained
-- in the expression in a list (ordered, no duplicates)
getVars :: ExprV -> [String]
getVars (Leaf (Constant x)) = []
getVars (Leaf (Variable x)) = [x]
getVars (UnaryOperation Minus x) = (getVars x)
getVars (BinaryOperation Plus (x) (y)) = sort (nub ((getVars x) ++ (getVars y)))
getVars (BinaryOperation Times (x) (y)) = sort (nub ((getVars x) ++ (getVars y)))

-- evalDeriv (20 points), evaluate the first derivative
-- with respect to the variable given in the second
-- arg. using (var, value) pairs given in the first arg.
evalDeriv :: [(String, Int)] -> String -> ExprV -> Int
evalDeriv _ _ (Leaf (Constant x)) = 0
evalDeriv y z (Leaf (Variable x)) = if x == z then 1  else 0
evalDeriv y z (UnaryOperation Minus x) = - (evalDeriv y z x)
evalDeriv z w (BinaryOperation Plus (x) (y)) = (evalDeriv z w x) + (evalDeriv z w y)
evalDeriv z w (BinaryOperation Times (x) (y)) = (evalExpr z x) * (evalDeriv z w y) + (evalExpr z y) * (evalDeriv z w x)

-- Looks like that's all! 

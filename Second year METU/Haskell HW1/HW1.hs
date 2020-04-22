module HW1 (
    form,
    constGrid,
    flatten,
    access,
    slice,
    vcat,
    hcat,
    without,
    matches2d
) where
import Data.List

-- do not modify the module declaration above!
-- this will ensure that you cannot load (compile)
-- the module without implementing all of the functions.

-- If you have functions you do not want to implement,
-- leave them as undefined or make them have another
-- default value. If you fully remove any of their definitions,
-- that will be a compilation error during evaluation,
-- and you will be eligible for (yay!) a 5 point deduction
-- (that's bad for your grade). Runtime errors in your code
-- (rather than compilation errors) are acceptable and will simply
-- result in you getting zero from the specific test case causing
-- an error.

-------------------------
-- Fellowship of the Grid (25, 5, 5, 5 points)
form :: [a] -> (Int, Int) -> [[a]]
form _ (0, _) = []
form x (i, j) = [take j x] ++ form (drop j x) (i - 1, j)


constGrid :: a -> (Int, Int) -> [[a]]
constGrid _ (0, _) = []
constGrid x (i, j) = [take j (repeat x)] ++ constGrid x (i - 1, j)


flatten :: [[a]] -> [a]
flatten x = concat x


access :: [[a]] -> (Int, Int) -> a
access x (i, j) = (x!!i)!!j

----------------------------
-- The Two Signatures (10, 5, 5, 10 points)
sliceHelp :: [[a]] -> (Int, Int) -> [[a]]
sliceHelp x (k, l) = [(take (l - k) (drop k (concat x)))]

slice :: [[a]] -> (Int, Int) -> (Int, Int) -> [[a]]
slice _ (o, p) _ | o == p = []
slice x (i, j) (k, l) = sliceHelp (take 1 (take (j - i) (drop i x))) (k, l) ++ slice x (i+1, j) (k, l)


vcat :: [[a]] -> [[a]] -> [[a]]
vcat x y = x ++ y


hcat :: [[a]] -> [[a]] -> [[a]]
hcat [] _ = []
hcat _ [] = []
hcat x y = [(concat ((take 1 x) ++ (take 1 y)))] ++ hcat (drop 1 x) (drop 1 y)


withoutHelp :: [[a]] -> (Int, Int) -> Int -> [[a]]
withoutHelp x _ m | m == length x = []
withoutHelp x (k, l) m = [(take k (concat(take 1 (drop m (x)))) ++ (drop l (concat(take 1 (drop m (x))))))] ++ withoutHelp x (k, l) (m+1)

without :: [[a]] -> (Int, Int) -> (Int, Int) -> [[a]]
without x (i, j) (k, l) = withoutHelp (take i x ++ drop j x) (k, l) 0
--without x (i, j) (k, l) = (slice x (0, i) (k, l)) ++ (slice x (j, (length x)) (l, round ((fromIntegral (length (concat x))) / (fromIntegral (length x)))))
----------------------------
-- Return of the Non-trivial (30 points, 15 subject to runtime constraints)
matches2dHelp :: Eq a => [[a]] -> [[a]] -> (Int, Int, Int) -> [(Int, Int)]
matches2dHelp x _ (l, m, n) | (l > length x) = []
matches2dHelp x y (l, m, n) | (n > length (concat (take 1 x))) = matches2dHelp x y (l+1, 0, (length (concat (take 1 y))))
matches2dHelp x y (l, m, n) | (slice x (l, (length y) + l) (m, n) == y) = [(l, m)] ++ matches2dHelp x y (l, (m+1), (n+1))
matches2dHelp x y (l, m, n) | (slice x (l, (length y) + l) (m, n) /= y) = [] ++ matches2dHelp x y (l, (m+1), (n+1))

matches2d :: Eq a => [[a]] -> [[a]] -> [(Int, Int)]
matches2d x y = matches2dHelp x y (0, 0, (length (concat (take 1 y))))
----------------------------
-- What is undefined? Just a value that will cause an error
-- when evaluated, from the GHC implementation:
-- undefined = error "Prelude.undefined"
-- But it allows your module to be compiled
-- since the function definitions will exist.

-- 1. It has been optimized for readability, understandability, and maintainability.
-- 2. It follows proper, modern Haskell conventions.
-- 3. It is clean, safe, and effective code.
-- 4. And it follows the philosophy of open to extensibility but closed off to modifications.
-- 5. Lastly, any other rules, aka modern industry standards or anything that I didn't include above, that I need to follow, since the above rules aren't exhaustive.

-- Problem #01
myremoveduplicates :: Eq a => [a] -> [a]
myremoveduplicates lst
    | null lst = []
    | elem (head lst) (tail lst) = myremoveduplicates (tail lst)
    | otherwise = (head lst) : myremoveduplicates (tail lst)

myremoveduplicates_pm :: Eq a => [a] -> [a]
myremoveduplicates_pm [] = []
myremoveduplicates_pm (x : xs) = if elem x xs then myremoveduplicates_pm (xs) else x : myremoveduplicates_pm (xs)

-- Problem #02
myintersection :: Eq a => [a] -> [a] -> [a]
myintersection lst1 lst2
    | null lst1 = []
    | elem (head lst1) lst2 = (head lst1) : myintersection (tail lst1) (lst2)
    | otherwise = myintersection (tail lst1) (lst2)

myintersection_pm :: Eq a => [a] -> [a] -> [a]
myintersection_pm [] lst2 = []
myintersection_pm (x1 : xs1) (lst2) = if elem x1 (lst2) then x1 : myintersection_pm (xs1) (lst2) else myintersection_pm (xs1) (lst2)

-- Problem #03
mynthtail :: Int -> [a] -> [a]
mynthtail n lst
    | n == 0 = lst
    | null lst = []
    | otherwise = mynthtail (n - 1) (tail lst)

mynthtail_pm :: Int -> [a] -> [a]
mynthtail_pm 0 lst = lst
mynthtail_pm n [] = []
mynthtail_pm n (x : xs) = mynthtail_pm (n - 1) (xs)

-- Problem #04
mylast :: [a] -> [a]
mylast lst
    | null lst = []
    | null (tail lst) = lst
    | otherwise = mylast (tail lst)

mylast_pm :: [a] -> [a]
mylast_pm [] = []
mylast_pm (x : []) = [x]
mylast_pm (x : xs) = mylast_pm (xs)

-- Problem #05
myreverse :: [a] -> [a]
myreverse lst1 = reverse_helper lst1 []
    where
        reverse_helper :: [a] -> [a] -> [a]
        reverse_helper lst1 lst2
            | null lst1 = lst2
            | otherwise = reverse_helper (tail lst1) (head lst1 : lst2)

myreverse_pm :: [a] -> [a]
myreverse_pm lst = reverse_helper_pm lst []
    where
        reverse_helper_pm :: [a] -> [a] -> [a]
        reverse_helper_pm [] lst = lst
        reverse_helper_pm (x : xs) lst = reverse_helper_pm (xs) (x : lst)

-- Problem #06
myreplaceall :: Eq a => a -> a -> [a] -> [a]
myreplaceall new_element old_element lst
    | null lst = []
    | (head lst) == old_element = new_element : myreplaceall (new_element) (old_element) (tail lst)
    | otherwise = (head lst) : myreplaceall (new_element) (old_element) (tail lst)

myreplaceall_pm :: Eq a => a -> a -> [a] -> [a]
myreplaceall_pm new_element old_element [] = []
myreplaceall_pm new_element old_element (x : xs) = if x == old_element then new_element : myreplaceall_pm (new_element) (old_element) (xs) else x : myreplaceall_pm (new_element) (old_element) (xs)

-- Problem #07
myordered :: Ord a => [a] -> Bool
myordered lst
    | null lst = True
    | null (tail lst) = True
    | otherwise =  ((head lst) <= (head (tail lst))) && (myordered (tail lst))

myordered_pm :: Ord a => [a] -> Bool
myordered_pm [] = True
myordered_pm (x : []) = True
myordered_pm (x : y : xs) = ((x) <= (y)) && (myordered_pm (y : xs))

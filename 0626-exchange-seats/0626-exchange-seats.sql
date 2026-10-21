# Write your MySQL query statement below
SELECT 
    CASE 
        -- Agar ID odd hai aur yeh aakhri row nahi hai, toh ID ko 1 badha do (jaise 1 ban gaya 2)
        WHEN MOD(id, 2) = 1 AND id < (SELECT COUNT(*) FROM Seat) THEN id + 1
        
        -- Agar ID even hai, toh ID ko 1 ghata do (jaise 2 ban gaya 1)
        WHEN MOD(id, 2) = 0 THEN id - 1
        
        -- Agar ID odd hai aur yeh bilkul aakhri row hai (jaise 5), toh wahi rehne do
        ELSE id
    END AS id,
    student
FROM Seat
ORDER BY id;
-- 코드를 입력하세요
SELECT
    SUM(CNT)
FROM
(
    SELECT
        IF(COUNT(*) > 0,1,0) AS CNT
    FROM 
        ANIMAL_INS 
    WHERE
        NAME IS NOT NULL
    GROUP BY
        NAME
) AS SUB;
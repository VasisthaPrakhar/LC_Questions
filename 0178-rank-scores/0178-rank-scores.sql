/* Write your T-SQL query statement below */
SELECT score,(SELECT COUNT(*) FROM (SELECT DISTINCT(score) FROM Scores) s  WHERE score>=s1.score) as rank FROM Scores s1 ORDER BY score DESC;

DELETE FROM Person a
USING Person b
WHERE a.email = b.email
  AND a.id > b.id;
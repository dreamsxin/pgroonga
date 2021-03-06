CREATE TABLE readings (
  katakanas text[]
);

INSERT INTO readings VALUES (ARRAY['ポストグレスキューエル', 'ポスグレ']);
INSERT INTO readings VALUES (ARRAY['グルンガ', 'グルン']);
INSERT INTO readings VALUES (ARRAY['ピージールンガ', 'ピーグルン']);

CREATE INDEX pgrn_index ON readings
  USING pgroonga (katakanas pgroonga_text_array_term_search_ops_v2);

SET enable_seqscan = off;
SET enable_indexscan = off;
SET enable_bitmapscan = on;

EXPLAIN (COSTS OFF)
SELECT katakanas
  FROM readings
 WHERE katakanas &^~| ARRAY['po', 'gu'];

SELECT katakanas
  FROM readings
 WHERE katakanas &^~| ARRAY['po', 'gu'];

DROP TABLE readings;

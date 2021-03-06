CREATE TABLE logs (
  record jsonb
);

CREATE INDEX pgroonga_index ON logs
  USING pgroonga (record pgroonga_jsonb_ops_v2);

INSERT INTO logs VALUES ('{}');

SET enable_seqscan = off;
SET enable_indexscan = off;
SET enable_bitmapscan = on;

SELECT count(*) FROM logs;

DROP TABLE logs;

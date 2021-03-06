CREATE TABLE memos (
  id int PRIMARY KEY,
  content text
);

INSERT INTO memos VALUES (1, 'PostgreSQL is a RDBMS.');
INSERT INTO memos VALUES (2, 'Groonga is fast full text search engine.');
INSERT INTO memos VALUES (3, 'PGroonga is a PostgreSQL extension that uses Groonga.');

CREATE INDEX pgroonga_index ON memos
  USING pgroonga (content pgroonga.text_full_text_search_ops);

UPDATE memos
 SET content = 'Mroonga is a MySQL storage engine that uses Groonga.'
 WHERE id = 3;

SELECT pgroonga.command('select ' ||
                        pgroonga.table_name('pgroonga_index') ||
                        ' --filter "pgroonga_tuple_is_alive(ctid)"'
                        ' --output_columns content')::json->>1
    AS body;

DROP TABLE memos;

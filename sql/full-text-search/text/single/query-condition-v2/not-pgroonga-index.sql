CREATE TABLE memos (
  id integer,
  content text
);

INSERT INTO memos VALUES (1, 'PostgreSQL is a RDBMS.');
INSERT INTO memos VALUES (2, 'Groonga is fast full text search engine.');
INSERT INTO memos VALUES (3, 'PGroonga is a PostgreSQL extension that uses Groonga.');

CREATE INDEX btree_index ON memos (content);

SELECT id, content
  FROM memos
 WHERE content &@~
       ('Groonga',
        NULL,
        'btree_index')::pgroonga_full_text_search_condition;

DROP TABLE memos;

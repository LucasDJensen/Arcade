Use master;
drop table Highscore;
CREATE DATABASE Arcade;
use Arcade;

CREATE TABLE HighScore (
  UI          int           NOT NULL IDENTITY (1, 1) PRIMARY KEY,
  PlayerName  varchar(255)  NOT NULL,
  Score       INT           NOT NULL,
  CreatedTime smalldatetime NOT NULL DEFAULT GETDATE()
);

INSERT INTO HighScore (PlayerName, Score) VALUES ();
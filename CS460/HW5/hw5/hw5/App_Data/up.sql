--CREATE TABLE [dbo].[MyPriorities]
--(
--	[ID]			INT IDENTITY (1,1)	NOT NULL,
--	[ItemPriority]	NVARCHAR(64)		NOT NULL,
--	CONSTRAINT [PK_dbo.MyProperties] PRIMARY KEY CLUSTERED ([ID] ASC)
CREATE TABLE [dbo].[Homeworks]
(
	[ID]			INT IDENTITY (1,1)	NOT NULL,
	[DueDate]		DATE				NOT NULL,
	[DueTime]		TIME				NOT NULL,
	[Department]	NVARCHAR(64)		NOT NULL,
	[CourseNumber]	INT					NOT NULL,
	[Title]			NVARCHAR(128)		NOT NULL,
	[ItemPriority]	NVARCHAR(128)		NOT NULL,
	[Notes]			NVARCHAR(512),
	CONSTRAINT [PK_dbo.Homeworks] PRIMARY KEY CLUSTERED ([ID] ASC),
);

INSERT INTO [dbo].[Homeworks] (DueDate, DueTime, Department, CourseNumber, ItemPriority, Title) VALUES
	('2019-11-21','00:00:00','CS',365,'High','Lab02'),
	('2019-11-30','22:00:00','Art',201,'Low','Self Portrait'),
	('2019-12-03','12:00:00','PSY',693,'Medium','Final Report'),
	('2019-11-21','15:30:00','CS',460,'Medium','Programming Final'),
	('2019-11-04','00:00:00','CS',365,'Low','Lab03')
GO
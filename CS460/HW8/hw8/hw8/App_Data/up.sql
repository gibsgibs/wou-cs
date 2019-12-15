CREATE TABLE [dbo].[Person]
(
	[PersonID]	INT IDENTITY (1,1)	NOT NULL,
	[Name]		NVARCHAR(50)		NOT NULL,
	CONSTRAINT [PK_dbo.Person] PRIMARY KEY CLUSTERED ([PersonID] ASC)
);

CREATE TABLE [dbo].[Coach]
(
	[CoachID]	INT IDENTITY (1,1)	NOT NULL,
	[PersonID]	INT					NOT NULL,
	CONSTRAINT [PK_dbo.Coach] PRIMARY KEY CLUSTERED ([CoachID] ASC),
	CONSTRAINT [FR_dbo.Coach.PersonID] FOREIGN KEY ([PersonID]) 
		REFERENCES [dbo].[Person] ([PersonID]) ON DELETE CASCADE
);

CREATE TABLE [dbo].[Team]
(
	[TeamID]	INT IDENTITY (1,1)	NOT NULL,
	[Name]		NVARCHAR(50)		NOT NULL,
	[CoachID]	INT					NOT NULL,	
	CONSTRAINT [PK_dbo.Team] PRIMARY KEY CLUSTERED ([TeamID] ASC),
	CONSTRAINT [FR_dbo.Team_dbo.CoachID] FOREIGN KEY ([CoachID]) 
		REFERENCES [dbo].[Coach] ([CoachID]) ON DELETE CASCADE
);

CREATE TABLE [dbo].[Athlete]
(
	[AthleteID]		INT IDENTITY (1,1)	NOT NULL,
	[PersonID]		INT					NOT NULL,
	[Gender]		NVARCHAR(20)		NOT NULL,
	[TeamID]		INT					NOT NULL,
	CONSTRAINT [PK_dbo.Athlete] PRIMARY KEY CLUSTERED ([AthleteID] ASC),
	CONSTRAINT [PK_dbo.Athlete_dbo.TeamID] FOREIGN KEY ([TeamID])
		REFERENCES [dbo].[Team] ([TeamID]) ON DELETE CASCADE,
	CONSTRAINT [FR_dbo.Athlete.PersonID] FOREIGN KEY ([PersonID]) 
		REFERENCES [dbo].[Person] ([PersonID]) ON DELETE NO ACTION
);

CREATE TABLE [dbo].[Meet]
(
	[MeetID]	INT IDENTITY (1,1)	NOT NULL,
	[Location]	NVARCHAR(50)		NOT NULL,
	[Date]		DATETIME			NOT NULL,			
	CONSTRAINT [PK_dbo.MeetID] PRIMARY KEY CLUSTERED ([MeetID] ASC)
);

CREATE TABLE [dbo].[Event]
(
	[EventID]	INT IDENTITY (1,1)	NOT NULL,
	[Name]		NVARCHAR(50)		NOT NULL,
	[Gender]	NVARCHAR(20)		NOT NULL,
	CONSTRAINT [PK_dbo.Event] PRIMARY KEY CLUSTERED ([EventID] ASC),
);

CREATE TABLE [dbo].[Result]
(
	[ResultID]	INT IDENTITY (1,1)	NOT NULL,
	[Time]		REAL				NOT NULL,
	[AthleteID]	INT					NOT NULL,
	[EventID]	INT					NOT NULL,
	[MeetID]	INT					NOT NULL,
	CONSTRAINT [PK_dbo.ResultID] PRIMARY KEY CLUSTERED ([ResultID] ASC),
	CONSTRAINT [PK_dbo.Result_dbo.AthleteID] FOREIGN KEY ([AthleteID])
		REFERENCES [dbo].[Athlete] ([AthleteID]) ON DELETE CASCADE,
	CONSTRAINT [PK_dbo.Result_dbo.EventID] FOREIGN KEY ([EventID])
		REFERENCES [dbo].[Event] ([EventID]) ON DELETE CASCADE,
	CONSTRAINT [PK_dbo.Result_dbo.MeetID] FOREIGN KEY ([MeetID])
		REFERENCES [dbo].[Meet] ([MeetID]) ON DELETE CASCADE,
);

CREATE TABLE [dbo].[TeamMeet]
(
	[TeamID]	INT		NOT NULL,
	[MeetID]	INT		NOT NULL,
	CONSTRAINT [PK_dbo.TeamMeet] PRIMARY KEY CLUSTERED ([TeamID], [MeetID]),
	CONSTRAINT [PK_dbo.TeamMeet_dbo.TeamID] FOREIGN KEY ([TeamID])
		REFERENCES [dbo].[Team] ([TeamID]) ON DELETE CASCADE,
	CONSTRAINT [PK_dbo.TeamMeet_dbo.MeetID] FOREIGN KEY ([MeetID])
		REFERENCES [dbo].[Meet] ([MeetID]) ON DELETE CASCADE
);
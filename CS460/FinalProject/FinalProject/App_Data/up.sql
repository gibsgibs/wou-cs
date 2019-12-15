CREATE TABLE [dbo].[Person]
(
	[PersonID]	INT IDENTITY (1,1)	NOT NULL,
	[FirstName] NVARCHAR(50)		NOT NULL,
	[LastName]	NVARCHAR(50)		NOT NULL,
	CONSTRAINT [PK_dbo.Person] PRIMARY KEY CLUSTERED ([PersonID] ASC)
);

CREATE TABLE [dbo].[Event]
(
	[EventID]		INT IDENTITY (1,1)	NOT NULL,
	[Title]			NVARCHAR(50)		NOT NULL,
	[Start]			DATETIME			NOT NULL,
	[Duration]		INT					NOT NULL,
	[Location]		NVARCHAR(50)		NOT NULL,
	[Coordinator]	INT					NOT NULL,
	CONSTRAINT [PK_dbo.Event] PRIMARY KEY CLUSTERED ([EventID] ASC),
	CONSTRAINT [FK_dbo.Event.Coordinator] FOREIGN KEY ([Coordinator])
		REFERENCES [dbo].[Person] ([PersonID]) ON DELETE CASCADE
);

CREATE TABLE [dbo].[RSVP]
(
	[RSVPID]			INT IDENTITY (1,1)	NOT NULL,
	[EventName]			INT					NOT NULL,
	[PersonAttending]	INT					NOT NULL,
	[TimeStamp]			DATETIME			NOT NUll,
	CONSTRAINT [PK_dbo.RSVP] PRIMARY KEY CLUSTERED ([RSVPID] ASC),
	CONSTRAINT [FK_dbo.RSVP.EventName] FOREIGN KEY ([EventName])
		REFERENCES [dbo].[Event] ([EventID]) ON DELETE CASCADE,
	CONSTRAINT [FK_dbo.RSVP.PersonAttending] FOREIGN KEY ([PersonAttending])
		REFERENCES [dbo].[Person] ([PersonID]) ON DELETE NO ACTION
);
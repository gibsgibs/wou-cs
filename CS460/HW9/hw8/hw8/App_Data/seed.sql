-- Create the table that holds the raw data from the .csv file.
CREATE TABLE [dbo].[AllData]
(
	[Location]	NVARCHAR(50),
	[MeetDate]	DATETIME,
	[Team]		NVARCHAR(50),
	[Coach]		NVARCHAR(50),
	[Event]		NVARCHAR(20),
	[Gender]	NVARCHAR(20),
	[Athlete]	NVARCHAR(50),
	[RaceTime]	REAL
);

-- Insert the data from the .csv file into the table.
-- Using a hardcoded, full path to the file, for ease of deploying later.
BULK INSERT [dbo].[AllData]
	FROM 'C:\Users\Gabriel\Desktop\CS460-repo\racetimes.csv'
	WITH
	(
		FIELDTERMINATOR = ',',
		ROWTERMINATOR = '\n',
		FIRSTROW = 2
	);

-- Insert all names of people in to the Person table.
INSERT INTO	[dbo].[Person] ([Name])
	SELECT DISTINCT Coach FROM [dbo].[AllData];
INSERT INTO	[dbo].[Person] ([Name])
	SELECT DISTINCT Athlete FROM [dbo].[AllData];

-- Insert the names of coaches from Person into the Coach table.
INSERT INTO [dbo].[Coach] ([PersonID])
	SELECT DISTINCT PersonID FROM [dbo].[Person], [dbo].[AllData]
	WHERE Person.Name = AllData.Coach;

-- Insert the data from AllData into the Team table.
INSERT INTO [dbo].[Team] ([Name], [CoachID])
	SELECT DISTINCT ad.Team, c.CoachID 
	FROM [dbo].AllData AS ad, [dbo].[Coach] AS c
	JOIN [dbo].Person AS p ON c.PersonID = p.PersonID
	WHERE ad.Coach = p.Name;

-- Insert the data from AllData/Person into the Athlete table.
INSERT INTO [dbo].[Athlete] ([PersonID], [Gender], [TeamID])
	SELECT DISTINCT p.PersonID, ad.Gender, t.TeamID
	FROM [dbo].[Person] AS p, [dbo].[AllData] AS ad, [dbo].[Team] AS t
	WHERE p.Name = ad.Athlete AND t.Name = ad.Team;

-- Insert the data from AllDate into the Meet table.
INSERT INTO [dbo].[Meet] ([Location], [Date])
	SELECT DISTINCT ad.Location, ad.MeetDate
	FROM [dbo].[AllData] AS ad;

-- Insert the data from AllData into the Event table.
INSERT INTO [dbo].[Event] ([Name], [Gender])
	SELECT DISTINCT ad.Event, ad.Gender
	FROM [dbo].[AllData] AS ad;

-- Insert the data from AllData/Athlete/Event/Meet into the Result table.
INSERT INTO [dbo].[Result] ([Time], [AthleteID], [EventID], [MeetID])
	SELECT DISTINCT ad.RaceTime, a.AthleteID, e.EventID, m.MeetID
	FROM [dbo].[AllData] AS ad
	JOIN [dbo].[Person] AS p ON ad.Athlete = p.Name
	JOIN [dbo].[Athlete] AS a ON p.PersonID = a.PersonID
	JOIN [dbo].[Meet] AS m ON ad.Location = m.Location
	JOIN [dbo].[Event] AS e ON ad.Event = e.Name
	WHERE e.Gender = ad.Gender;

-- Insert the data from Team/Meet into the TeamMeet table.
INSERT INTO [dbo].[TeamMeet] ([TeamID], [MeetID])
	SELECT DISTINCT t.TeamID, m.MeetID
	FROM [dbo].[Meet] AS m, [dbo].[Team] AS t
	JOIN [dbo].[AllData] AS ad ON t.Name = ad.Team
	WHERE m.Location = ad.Location;

-- This is not a permanent table, so we are dropping it here.
DROP TABLE [dbo].[AllData];
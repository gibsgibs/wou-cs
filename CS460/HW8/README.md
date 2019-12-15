# Homework 8 - TrackTracker Website
**An MVC project using a multi-table relational database that I designed.**
___

*The following notes are being added/commited directly from github.com on branch hw8.*

**Notes**
1. Updated to Bootstrap 4.3.1, and set up the landing page's navbar to work with it.  
2. Switched to a new branch to create the database.  
	- **To add .mdf file:** Solution Explorer -> App_Data -> Add -> New Item... -> SQL Server Database
	- **To connect the database:** Server Exploer -> Data Connections -> Add Connection... -> Browse
3. Created three new .sql files; up.sql, down.sql and seed.sql.
	- **To create new .sql files:** Solution Explorer -> App_Data -> Add -> New Item... -> Text File
		- ***Make sure it is named with .sql***
	- For examples of setting up tables using T-SQL, checkout App_Data -> up.sql.
4. Installed EntityFramwork by Microsoft.
	- Tools -> Nuget Package Manager -> Manage Nuget Packages for Solution... -> Browse
5. Created all the models and the context class for the database.
	- **To create the models:** Models -> Add -> New Item... -> Data -> ADO.NET Entity Data Model -> db name appended with Context -> Code First from database -> Select all tables  
6. Created a new folder called DAL, and placed the context class found in the Models folder into the new folder.
	- **To create a new folder:** Right click on project -> Add -> New Folder
7. Changed the namespace in the context class from projectName.Model to projectName.DAL, and added the statement `using projectName.Models;` to the top of the file.
8. Built the solution.
9. Created CRUD pages.
	- **To create CRUD pages:** Controller -> MVC5 with Views using Entity Framework
10. Created a new folder for ViewModels inside of the Models folder.
11. Created a new AthleteViewModel inside ViewModels. Note that `@model hw8.Models.ViewModels.AthleteViewModel` needs to be added to the top of a view using the ViewModel.
12. Decided that I wanted all three create pages to be part of the same controller, so I deleted most of the CRUD pages and put the Action Mthods in the Home Controller.
13. For the DatePicker in the Create Meet I used this site: https://www.syncfusion.com/aspnet-mvc-ui-controls/datepicker. Pretty cool stuff.
14. For Requirement 2, I created a new contoller called `AthletesController.cs` and got rid of all the views except for `Details.cshtml` and `Index.cshtml`.
15. 

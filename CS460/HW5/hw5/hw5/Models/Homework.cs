using System;
using System.Collections.Generic;
using System.Linq;
using System.Web.Mvc;
using System.ComponentModel;
using System.ComponentModel.DataAnnotations;
using System.Globalization;

/*
    [ID]            INT IDENTITY(1,1)   NOT NULL,
    [DueDate]       DATE                NOT NULL,
	[DueTime]       TIME                NOT NULL,
	[Department]    NVARCHAR(64)        NOT NULL,
    [CourseNumber]  INT                 NOT NULL,
	[ItemPriority]  INT                 NOT NULL,
    [Title]         NVARCHAR(128)       NOT NULL,
    [Notes]         NVARCHAR(512),
	CONSTRAINT[PK_dbo.Homeworks] PRIMARY KEY CLUSTERED([ID] ASC)
*/

namespace hw5.Models
{
    public class Homework
    {
        [Key]
        public int ID { get; set; }

        [DisplayName("Due Date"), Required]
        public DateTime DueDate { get; set; }

        [DisplayName("Due Time"), Required]
        [RegularExpression(@"^([0-1][0-9]|2[0-3]):[0-5][0-9]:[0-5][0-9]$")]
        public TimeSpan DueTime { get; set; }

        [DisplayName("Department"), Required]
        [StringLength(64)]
        public string Department { get; set; }

        [DisplayName("Course Number"), Required]
        public int CourseNumber { get; set; }

        [DisplayName("Priority"), Required]
        public string ItemPriority { get; set; }

        [DisplayName("Title"), Required]
        [StringLength(128)]
        public string Title { get; set; }

        [DisplayName("Notes")]
        [StringLength(512)]
        public string Notes { get; set; }

        public string DueDateAsString
        {
            get
            {
                return DueDate.Date.ToShortDateString();
            }
        }

        public string TimeLeft
        {
            get
            {
                TimeSpan time;
                bool overdue = false;
                if (DateTime.Now > DueDate)
                {
                    time = DateTime.Now - DueDate;
                    overdue = true;
                }
                else
                {
                    time = DueDate - DateTime.Now;
                }
                int days = time.Days;
                int hours = time.Hours;
                int minutes = time.Minutes;
                int seconds = time.Seconds;

                string daysString = (days > 0) ? days.ToString() + ((time.Days == 1) ? " day, " : " days, ") : "";
                string hoursString = (hours > 0) ? time.Hours.ToString() + ((time.Hours == 1) ? " hour, " : " hours, ") : "";
                string minutesString = (minutes > 0) ? time.Minutes.ToString() + ((time.Minutes == 1) ? " minute and " : " minutes and ") : "";
                string secondsString = (seconds > 0) ? time.Seconds.ToString() + ((time.Seconds == 1) ? " second." : " seconds.") : "";

                if (overdue)
                {
                    return "Overdue by " + daysString + hoursString + minutesString + secondsString;
                }
                else
                {
                    return "Due in " + daysString + hoursString + minutesString + secondsString;
                }
            }
        }
    }
    public enum Priorities
    {
        Low,
        Medium,
        High
    }
}
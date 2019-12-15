using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace hw8.Models.ViewModels
{
    public class AthleteViewModel
    {
        public AthleteViewModel() { }

        public AthleteViewModel(Athlete athlete)
        {
            AthleteID = athlete.AthleteID;
            AthleteName = athlete.Person.Name;
            TeamName = athlete.Team.Name;
            Gender = athlete.Gender;
        }

        public int AthleteID { get; set; }
        [Required]
        [Display(Name = "Athlete Name")]
        [StringLength(50)]
        public string AthleteName { get; set; }
        
        [Required]
        [Display(Name = "Team Name")]
        [StringLength(50)]
        public string TeamName { get; set; }

        [Required]
        [Display(Name = "Gender")]
        [StringLength(20)]
        public string Gender { get; set; }
    }
    public enum Gender
    {
        Boys,
        Girls
    }
}
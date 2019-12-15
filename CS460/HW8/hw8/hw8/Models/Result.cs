namespace hw8.Models
{
    using System;
    using System.Collections.Generic;
    using System.ComponentModel.DataAnnotations;
    using System.ComponentModel.DataAnnotations.Schema;
    using System.Data.Entity.Spatial;

    [Table("Result")]
    public partial class Result
    {
        public int ResultID { get; set; }

        [Required]
        [Display(Name = "Time")]
        public float Time { get; set; }

        [Required]
        [Display(Name = "Athlete")]
        public int AthleteID { get; set; }

        [Required]
        [Display(Name = "Event")]
        public int EventID { get; set; }

        [Required]
        [Display(Name = "Meet")]
        public int MeetID { get; set; }

        public virtual Athlete Athlete { get; set; }

        public virtual Event Event { get; set; }

        public virtual Meet Meet { get; set; }
    }
}

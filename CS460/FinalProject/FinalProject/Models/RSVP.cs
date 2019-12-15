namespace FinalProject.Models
{
    using System;
    using System.Collections.Generic;
    using System.ComponentModel.DataAnnotations;
    using System.ComponentModel.DataAnnotations.Schema;
    using System.Data.Entity.Spatial;

    [Table("RSVP")]
    public partial class RSVP
    {
        public int RSVPID { get; set; }

        public int EventName { get; set; }

        public int PersonAttending { get; set; }

        public DateTime TimeStamp { get; set; }

        public virtual Event Event { get; set; }

        public virtual Person Person { get; set; }
    }
}

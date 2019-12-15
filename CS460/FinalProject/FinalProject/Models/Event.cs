namespace FinalProject.Models
{
    using System;
    using System.Collections.Generic;
    using System.ComponentModel.DataAnnotations;
    using System.ComponentModel.DataAnnotations.Schema;
    using System.Data.Entity.Spatial;

    [Table("Event")]
    public partial class Event
    {
        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Usage", "CA2214:DoNotCallOverridableMethodsInConstructors")]
        public Event()
        {
            RSVPs = new HashSet<RSVP>();
        }

        public int EventID { get; set; }

        [Required]
        [StringLength(50)]
        public string Title { get; set; }

        public DateTime Start { get; set; }

        public int Duration { get; set; }

        [Required]
        [StringLength(50)]
        public string Location { get; set; }

        public int Coordinator { get; set; }

        public virtual Person Person { get; set; }

        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Usage", "CA2227:CollectionPropertiesShouldBeReadOnly")]
        public virtual ICollection<RSVP> RSVPs { get; set; }
    }
}

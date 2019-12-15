using FinalProject.Models;
namespace FinalProject.DAL
{
    using System;
    using System.Data.Entity;
    using System.ComponentModel.DataAnnotations.Schema;
    using System.Linq;

    public partial class FDBContext : DbContext
    {
        public FDBContext()
            : base("name=FDBContext")
        {
        }

        public virtual DbSet<Event> Events { get; set; }
        public virtual DbSet<Person> People { get; set; }
        public virtual DbSet<RSVP> RSVPs { get; set; }

        protected override void OnModelCreating(DbModelBuilder modelBuilder)
        {
            modelBuilder.Entity<Event>()
                .HasMany(e => e.RSVPs)
                .WithRequired(e => e.Event)
                .HasForeignKey(e => e.EventName);

            modelBuilder.Entity<Person>()
                .HasMany(e => e.Events)
                .WithRequired(e => e.Person)
                .HasForeignKey(e => e.Coordinator);

            modelBuilder.Entity<Person>()
                .HasMany(e => e.RSVPs)
                .WithRequired(e => e.Person)
                .HasForeignKey(e => e.PersonAttending)
                .WillCascadeOnDelete(false);
        }
    }
}

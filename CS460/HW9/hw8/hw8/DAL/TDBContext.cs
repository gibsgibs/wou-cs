using hw8.Models;

namespace hw8.DAL
{
    using System;
    using System.Data.Entity;
    using System.ComponentModel.DataAnnotations.Schema;
    using System.Linq;

    public partial class TDBContext : DbContext
    {
        // For local deployment: use '"name=TBDContext"'.
        // For cloud deployment: use '"name=TBDContext_Azure"'.
        public TDBContext()
            : base("name=TDBContext")
        {
        }

        public virtual DbSet<Athlete> Athletes { get; set; }
        public virtual DbSet<Coach> Coaches { get; set; }
        public virtual DbSet<Event> Events { get; set; }
        public virtual DbSet<Meet> Meets { get; set; }
        public virtual DbSet<Person> People { get; set; }
        public virtual DbSet<Result> Results { get; set; }
        public virtual DbSet<Team> Teams { get; set; }

        protected override void OnModelCreating(DbModelBuilder modelBuilder)
        {
            modelBuilder.Entity<Meet>()
                .HasMany(e => e.Teams)
                .WithMany(e => e.Meets)
                .Map(m => m.ToTable("TeamMeet").MapLeftKey("MeetID").MapRightKey("TeamID"));

            modelBuilder.Entity<Person>()
                .HasMany(e => e.Athletes)
                .WithRequired(e => e.Person)
                .WillCascadeOnDelete(false);
        }
    }
}

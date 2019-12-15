using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Data.Entity;
using hw5.Models;

namespace hw5.DAL
{
    public class HomeworkContext : DbContext
    {
        public HomeworkContext() : base("name=Database")
        {
            Database.SetInitializer<HomeworkContext>(null);
        }

        public virtual DbSet<Homework> Homeworks { get; set; }

        protected override void OnModelCreating(DbModelBuilder modelBuilder)
        {
            base.OnModelCreating(modelBuilder);
            modelBuilder.Entity<Homework>().ToTable("Homeworks");
        }
    }
}
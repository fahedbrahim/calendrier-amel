#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"

struct date
{

char date_naissance[400];

};
typedef struct date date;

void
on_button_valider_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
date d;
GtkWidget *acceuil;
GtkWidget *affichage;
GtkWidget *label_date;
GtkWidget *calendar1;

char jour[50];
char mois[50];
char annee[50];

int *jour1;
int mois1;
int *annee1;

acceuil=lookup_widget(button,"acceuil");

calendar1=lookup_widget(button,"calendar1");

gtk_calendar_get_date(calendar1,&annee1,&mois1,&jour1);

mois1++;
sprintf(jour,"%u", jour1);
sprintf(mois,"%u", mois1);
sprintf(annee,"%u", annee1);

	strcat(d.date_naissance,jour);
	strcat(d.date_naissance,"/");
	strcat(d.date_naissance,mois);
        strcat(d.date_naissance,"/");
	strcat(d.date_naissance,annee);

gtk_widget_destroy(acceuil);
affichage=create_affichage();
gtk_widget_show(affichage);

label_date=lookup_widget(affichage,"label_date");

gtk_label_set_text(GTK_LABEL(label_date),d.date_naissance);
}


void
on_button_retour_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *acceuil;
GtkWidget *affichage;
affichage=lookup_widget(button,"affichage");

gtk_widget_destroy(affichage);
acceuil=create_acceuil();
gtk_widget_show(acceuil);
}


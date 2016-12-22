#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::setEnglishContent()
{
    ui->label->setText(tr(""));
}

void Dialog::setSerbianContnet()
{

    ui->label->setText(tr("Kratko objašnjenje rada programa"));

    QString definicija = QString("");

    definicija.append("Definicija: Vremenski konveksni omotač skupa tačaka je najmanji skup koji sadrži sve tačke i najbrže puteve medju njima");

    definicija.append("\n");
    definicija.append("Autoput je prava u ravni za koju važi da je vremenska razdaljina od dve tačke na njoj kraća nego od druge dve tačke istog rastojanja van autoputa. Ili drugačije rečeno, ako je kretanje van autoputa brzine 1 onda je na autoputu brzine strogo veće od 1.");

    definicija.append("\n");
    definicija.append("Definicija: Vremenski konveksni omotač skupa tačaka sa autoputem, je najmanji skup koji sadrži sve tačke, autoput i najbrže puteve između tačaka.");

    definicija.append("\n");


    definicija.append("Tačke se razvrstavaju u klastere (particije, podskupove), za koje važi da najbrži put između dve tačke u klasteru, a najbrži put između tačaka van klastera koristi autoput.\n");
    ui->textEdit->setText(definicija);
    ui->textEdit->setReadOnly(true);

    QString opisAloritma("");

    opisAloritma.append("Rad algoritma:\n");
    opisAloritma.append("Ideja algoritma je slična kao algoritma za konstrukciju konveksnog omotača u ravni.");
    opisAloritma.append("Prvo se tačke sortiraju pa se obrađuje jedna po jedna tačka.\n");

    opisAloritma.append("Pri obradi sledeće tačke posmatra se da li tačka pripada nekom od već postojećih klastera, tako što se proveri da li se nalazi iznad ili ispod granice.");

    opisAloritma.append("\n");

    opisAloritma.append("U slučaju L1 norme, granica klastera je izlomljena linija, i dovoljno je proveriti da li je tačka iznad ili ispod granice.");
    opisAloritma.append("\n");

    opisAloritma.append("Ako je tačka iznad granice, znači da pripada klasteru, potrebno ju je dodati i promeniti granicu klastera (kao na slici iznad).");

    opisAloritma.append("Ako ne pripada ni jednom od klastera onda se pravi novi klaster koji sadrži samo datu tačku.\n");

    ui->textEdit_2->setText(opisAloritma);
    ui->textEdit_2->setReadOnly(true);
}

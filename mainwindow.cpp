#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<string>
#include<QMap>
#include<QVector>
#include<QMetaEnum>
#include<QObject>
#include<QTcpServer>

static QString card_pic_addr[52] = {  "../pic/ha.jpg","../pic/h2.jpg","../pic/h3.jpg","../pic/h4.jpg","../pic/h5.jpg",
                "../pic/h6.jpg","../pic/h7.jpg","../pic/h8.jpg","../pic/h9.jpg","../pic/ht.jpg",
                "../pic/hj.jpg","../pic/hq.jpg","../pic/hk.jpg",

                "../pic/da.jpg","../pic/d2.jpg","../pic/d3.jpg","../pic/d4.jpg","../pic/d5.jpg",
                "../pic/d6.jpg","../pic/d7.jpg","../pic/d8.jpg","../pic/d9.jpg","../pic/dt.jpg",
                "../pic/dj.jpg","../pic/dq.jpg","../pic/dk.jpg",

                "../pic/ca.jpg","../pic/c2.jpg","../pic/c3.jpg","../pic/c4.jpg","../pic/c5.jpg",
                "../pic/c6.jpg","../pic/c7.jpg","../pic/c8.jpg","../pic/c9.jpg","../pic/ct.jpg",
                "../pic/cj.jpg","../pic/cq.jpg","../pic/ck.jpg",

                "../pic/sa.jpg","../pic/s2.jpg","../pic/s3.jpg","../pic/s4.jpg","../pic/s5.jpg",
                "../pic/s6.jpg","../pic/s7.jpg","../pic/s8.jpg","../pic/s9.jpg","../pic/st.jpg",
                "../pic/sj.jpg","../pic/sq.jpg","../pic/sk.jpg",

};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),CARDINONESUIT(13),card_pos(1),card_suit(NUMOFSUIT),card_num(NUMOFNUM)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::normal_status_bar_show()
{
    QString msg=" * ",msg1=" * ";
    if(card_suit<NUMOFSUIT)
    {
        QMetaEnum metaEnum = QMetaEnum::fromType<MainWindow::CARDSUIT>();
        msg = metaEnum.valueToKey(card_suit);
    }

    if(card_num<NUMOFNUM)
    {
        switch(card_num){
        case TWO:
        case THREE:
        case FOUR:
        case FIVE:
        case SIX:
        case SEVEN:
        case EIGHT:
        case NINE:
            msg1 = QString::number(card_num+1,10);
            break;
        case ACE:
            msg1 = "A";
            break;
        case TEN:
            msg1 = "T";
            break;
        case JACK:
            msg1 = "J";
            break;
        case QUEEN:
            msg1 = "Q";
            break;
        case KING:
            msg1 = "K";
            break;
        default:
            break;
        }
    }
    this->ui->statusBar->showMessage(msg+" "+msg1);
}

void MainWindow::click_callback()
{
    normal_status_bar_show();
    if(card_suit<NUMOFSUIT&&card_num<NUMOFNUM)
    {
        if(1==card_pos||6==card_pos)
        {
            card_showed.clear();
            this->ui->label->setPixmap(QPixmap(
                           card_pic_addr[card_suit*CARDINONESUIT+card_num]));
            this->ui->label_2->setPixmap(QPixmap(
                            QString::fromUtf8("../pic/back.png")));
            this->ui->label_3->setPixmap(QPixmap(
                            QString::fromUtf8("../pic/back.png")));
            this->ui->label_4->setPixmap(QPixmap(
                            QString::fromUtf8("../pic/back.png")));
            this->ui->label_5->setPixmap(QPixmap(
                            QString::fromUtf8("../pic/back.png")));
            card_pos=2;
            card_showed.append(QPair<CARDSUIT,CARDNUM>(card_suit,card_num));

        }
        else
        {
            if(card_showed.contains(QPair<CARDSUIT,CARDNUM>(card_suit,card_num)))
            {
                this->ui->statusBar->showMessage("error:the card already showed!");
            }
            else
            {
                card_showed.append(QPair<CARDSUIT,CARDNUM>(card_suit,card_num));
                switch (card_pos) {
                case 2:
                    this->ui->label_2->setPixmap(QPixmap(
                                    card_pic_addr[card_suit*CARDINONESUIT+card_num]));
                    card_pos=3;
                    break;
                case 3:
                    this->ui->label_3->setPixmap(QPixmap(
                                    card_pic_addr[card_suit*CARDINONESUIT+card_num]));
                    card_pos=4;
                    break;
                case 4:
                    this->ui->label_4->setPixmap(QPixmap(
                                    card_pic_addr[card_suit*CARDINONESUIT+card_num]));
                    card_pos=5;
                    break;
                case 5:
                    this->ui->label_5->setPixmap(QPixmap(
                                    card_pic_addr[card_suit*CARDINONESUIT+card_num]));
                    card_pos=6;
                    break;
                default:
                    break;
                }

            }
        }
        card_num = NUMOFNUM;
        card_suit = NUMOFSUIT;
    }

    return;

}

//----------------------button click---------------------------

void MainWindow::on_heart_clicked()
{
    card_suit=HEART;
    click_callback();
}


void MainWindow::on_diamond_clicked()
{
    card_suit=DIAMOND;
    click_callback();
}

void MainWindow::on_club_clicked()
{
    card_suit=CLUB;
    click_callback();
}

void MainWindow::on_spade_clicked()
{
    card_suit=SPADE;
    click_callback();
}

void MainWindow::on_ace_clicked()
{
    card_num=ACE;
    click_callback();
}

void MainWindow::on_two_clicked()
{
    card_num=TWO;
    click_callback();
}

void MainWindow::on_three_clicked()
{
    card_num=THREE;
    click_callback();
}

void MainWindow::on_four_clicked()
{
    card_num=FOUR;
    click_callback();
}

void MainWindow::on_five_clicked()
{
    card_num=FIVE;
    click_callback();
}

void MainWindow::on_six_clicked()
{
    card_num=SIX;
    click_callback();
}

void MainWindow::on_seven_clicked()
{
    card_num=SEVEN;
    click_callback();
}

void MainWindow::on_eight_clicked()
{
    card_num=EIGHT;
    click_callback();
}

void MainWindow::on_nine_clicked()
{
    card_num=NINE;
    click_callback();
}

void MainWindow::on_ten_clicked()
{
    card_num=TEN;
    click_callback();
}

void MainWindow::on_jack_clicked()
{
    card_num=JACK;
    click_callback();
}

void MainWindow::on_queen_clicked()
{
    card_num=QUEEN;
    click_callback();
}

void MainWindow::on_king_clicked()
{
    card_num=KING;
    click_callback();
}

void MainWindow::on_redo_clicked()
{
    card_pos==1?1:card_pos--;
    switch(card_pos)
    {
    case 1:
        this->ui->label->setPixmap(QPixmap(
                        QString::fromUtf8("../pic/back.png")));
        break;
    case 2:
        this->ui->label_2->setPixmap(QPixmap(
                        QString::fromUtf8("../pic/back.png")));
        break;
    case 3:
        this->ui->label_3->setPixmap(QPixmap(
                        QString::fromUtf8("../pic/back.png")));
        break;
    case 4:
        this->ui->label_4->setPixmap(QPixmap(
                        QString::fromUtf8("../pic/back.png")));
        break;
    case 5:
        this->ui->label_5->setPixmap(QPixmap(
                        QString::fromUtf8("../pic/back.png")));
        break;
    default:
        break;
    }
    if(!card_showed.isEmpty())
    {
        card_showed.removeLast();
    }
    card_num=NUMOFNUM;
    card_suit=NUMOFSUIT;
}

void MainWindow::on_reset_clicked()
{
    this->ui->label->setPixmap(QPixmap(
                    QString::fromUtf8("../pic/back.png")));
    this->ui->label_2->setPixmap(QPixmap(
                    QString::fromUtf8("../pic/back.png")));
    this->ui->label_3->setPixmap(QPixmap(
                    QString::fromUtf8("../pic/back.png")));
    this->ui->label_4->setPixmap(QPixmap(
                    QString::fromUtf8("../pic/back.png")));
    this->ui->label_5->setPixmap(QPixmap(
                    QString::fromUtf8("../pic/back.png")));
    card_pos = 1;
    card_showed.clear();
    card_num = NUMOFNUM;
    card_suit = NUMOFSUIT;
}

//--------------------card kind check-------------------------

void MainWindow::royal_flush_check()
{
    QVector<CARDSUIT> suit;
    card_kind_cnt[RoyalFlush] = 0;
    int n = card_showed.size();
    if(3==n){
        for (QPair<CARDSUIT,CARDNUM> x:card_showed) {
            if(x.second>=TEN||x.second==ACE)
            {
                card_kind_cnt[RoyalFlush]++;
            }
        }
    }
    else
    {
        int card_suit_cnt[NUMOFSUIT]={0,0,0,0};
        for (QPair<CARDSUIT,CARDNUM> x:card_showed)
        {
            if(x.second>=TEN||x.second==ACE)
            {
               card_suit_cnt[x.first]++;
            }
        }
        for (int i:card_suit_cnt)
        {
            if(i >= n-2)
            {
                card_kind_cnt[RoyalFlush]++;
            }
        }
    }
}
void MainWindow::straight_flush_check()
{
    int n = card_showed.size();
    card_kind_cnt[StraightFlush] = 0;
    QMap<CARDSUIT,int> temp;
    QMap<CARDSUIT,CARDNUM> card_temp;
    for(QPair<CARDSUIT,CARDNUM> x:card_showed)
    {
        if(temp.contains(x.first))
        {
            temp[x.first]++;

        }
        else {
            temp.insert(x.first,1);
            card_temp.insert(x.first,x.second);
        }
    }
    QMap<CARDSUIT,int>::iterator it;
    for(it=temp.begin();it!=temp.end();it++)
    {
       if(it.value() >= (n-2))
       {
           card_kind_cnt[Flush]++;
       }
    }
}
void MainWindow::four_of_a_kind_check()
{
    int n = card_showed.size();
    card_kind_cnt[FourOfKind] = 0;
    if(3==n)
    {
        card_kind_cnt[FourOfKind] = 624;
    }
    else
    {
        QMap<CARDNUM,int> temp;
        for(QPair<CARDSUIT,CARDNUM> x:card_showed)
        {
            if(temp.contains(x.second))
            {
                temp[x.second]++;
            }
            else {
                temp.insert(x.second,1);
            }
        }
        if(4==n)
        {
            card_kind_cnt[FourOfKind] = temp.size();
        }
        if(5==n)
        {
            QMap<CARDNUM,int>::iterator it;
            for(it=temp.begin();it!=temp.end();it++)
            {
               if(it.value() > 1)
               {
                   card_kind_cnt[FourOfKind]++;
               }
            }
        }

    }

}
void MainWindow::full_house_check()
{
    int n = card_showed.size();
    card_kind_cnt[FullHouse] = 0;
}
void MainWindow::flush_check()
{
    int n = card_showed.size();
    card_kind_cnt[Flush] = 0;
    QMap<CARDSUIT,int> temp;
    for(QPair<CARDSUIT,CARDNUM> x:card_showed)
    {
        if(temp.contains(x.first))
        {
            temp[x.first]++;
        }
        else {
            temp.insert(x.first,1);
        }
    }
    QMap<CARDSUIT,int>::iterator it;
    for(it=temp.begin();it!=temp.end();it++)
    {
       if(it.value() >= (n-2))
       {
           card_kind_cnt[Flush]++;
       }
    }

}
void MainWindow::high_card_check()
{
    card_kind_cnt[HighCard]=2598960;
}
void MainWindow::on_ok_clicked()
{
   this->ui->textBrowser->clear();
   if(card_showed.size()<3)
   {
       this->ui->statusBar->showMessage("info:card showed must be 3 or more!");
   }
   else {
       QString msg;

       royal_flush_check();
       straight_flush_check();
       four_of_a_kind_check();
       full_house_check();
       flush_check();
       high_card_check();

       msg.sprintf("Royal Flush:    %d\n"
                   "Straight Flush: %d\n"
                   "Four Of A Kind: %d\n"
                   "Full House:     %d\n"
                   "Flush:          %d\n"
                   "Straight:       %d\n"
                   "Three Of A Kind:%d\n"
                   "Two Pair:       %d\n"
                   "One Pair:       %d\n"
                   "High Card:      %d\n",
                   card_kind_cnt[RoyalFlush],
                   card_kind_cnt[StraightFlush],
                   card_kind_cnt[FourOfKind],
                   card_kind_cnt[FullHouse],
                   card_kind_cnt[Flush],
                   card_kind_cnt[Straight],
                   card_kind_cnt[ThreeOfKind],
                   card_kind_cnt[TwoPair],
                   card_kind_cnt[OnePair],
                   card_kind_cnt[HighCard]);
       this->ui->textBrowser->setText(msg);

   }
}

void MainWindow::on_open_clicked()
{
    QTcpServer tcpServer;

    tcpServer.listen(QHostAddress::Any,9000);

    connect(tcpServer,)

}

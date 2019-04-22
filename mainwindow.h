#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    enum CARDSUIT{
        HEART,
        DIAMOND,
        CLUB,
        SPADE,
        NUMOFSUIT
    };
    Q_ENUM(CARDSUIT)
    enum CARDNUM{
        ACE,
        TWO,
        THREE,
        FOUR,
        FIVE,
        SIX,
        SEVEN,
        EIGHT,
        NINE,
        TEN,
        JACK,
        QUEEN,
        KING,
        NUMOFNUM
    };
    Q_ENUM(CARDNUM)
    enum CARDKIND{
        RoyalFlush,
        StraightFlush,
        FourOfKind,
        FullHouse,
        Flush,
        Straight,
        ThreeOfKind,
        TwoPair,
        OnePair,
        HighCard,
        NUMOFKIND
    };
    Q_ENUM(CARDKIND)
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void click_callback();
    void normal_status_bar_show();
    void royal_flush_check();
    void straight_flush_check();
    void four_of_a_kind_check();
    void full_house_check();
    void flush_check();
    void high_card_check();

private slots:
    void on_heart_clicked();
    void on_diamond_clicked();

    void on_club_clicked();

    void on_spade_clicked();

    void on_ace_clicked();

    void on_two_clicked();

    void on_three_clicked();

    void on_four_clicked();

    void on_five_clicked();

    void on_six_clicked();

    void on_seven_clicked();

    void on_eight_clicked();

    void on_nine_clicked();

    void on_ten_clicked();

    void on_jack_clicked();

    void on_queen_clicked();

    void on_king_clicked();

    void on_redo_clicked();

    void on_reset_clicked();

    void on_ok_clicked();

    void on_open_clicked();

private:
    Ui::MainWindow *ui;
    const int8_t CARDINONESUIT;
    int8_t card_pos;
    CARDSUIT card_suit ;
    CARDNUM card_num ;
    int card_kind_cnt[NUMOFKIND];
    QVector<QPair<CARDSUIT,CARDNUM>> card_showed;
};

#endif // MAINWINDOW_H

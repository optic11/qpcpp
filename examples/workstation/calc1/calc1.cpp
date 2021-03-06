//$file${.::calc1.cpp} #######################################################
//
// Model: calc1.qm
// File:  ${.::calc1.cpp}
//
// This code has been generated by QM 4.3.1 (https://www.state-machine.com/qm).
// DO NOT EDIT THIS FILE MANUALLY. All your changes will be lost.
//
// This program is open source software: you can redistribute it and/or
// modify it under the terms of the GNU General Public License as published
// by the Free Software Foundation.
//
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
// or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
// for more details.
//
//$endhead${.::calc1.cpp} ####################################################
#include "qpcpp.h" // QP/C++
#include "bsp.h"   // board support package
#include "calc1.h" // application

//$declare${SMs::Calc} #######################################################
//${SMs::Calc} ...............................................................
class Calc : public QP::QHsm {
private:
    double op1;
    uint8_t oper;

public:
    Calc();

protected:
    static QP::QState initial(Calc * const me, QP::QEvt const * const e);
    static QP::QState on(Calc * const me, QP::QEvt const * const e);
    static QP::QState error(Calc * const me, QP::QEvt const * const e);
    static QP::QState ready(Calc * const me, QP::QEvt const * const e);
    static QP::QState result(Calc * const me, QP::QEvt const * const e);
    static QP::QState begin(Calc * const me, QP::QEvt const * const e);
    static QP::QState operand1(Calc * const me, QP::QEvt const * const e);
    static QP::QState zero1(Calc * const me, QP::QEvt const * const e);
    static QP::QState int1(Calc * const me, QP::QEvt const * const e);
    static QP::QState frac1(Calc * const me, QP::QEvt const * const e);
    static QP::QState negated1(Calc * const me, QP::QEvt const * const e);
    static QP::QState opEntered(Calc * const me, QP::QEvt const * const e);
    static QP::QState operand2(Calc * const me, QP::QEvt const * const e);
    static QP::QState zero2(Calc * const me, QP::QEvt const * const e);
    static QP::QState int2(Calc * const me, QP::QEvt const * const e);
    static QP::QState frac2(Calc * const me, QP::QEvt const * const e);
    static QP::QState negated2(Calc * const me, QP::QEvt const * const e);
    static QP::QState final(Calc * const me, QP::QEvt const * const e);
};
//$enddecl${SMs::Calc} #######################################################

static Calc l_calc;    // the only instance of the Calc class

// global-scope definitions -----------------------------------
QP::QHsm * const the_calc = &l_calc; // "opaque" pointer to HSM

// Check for the minimum required QP version
#if (QP_VERSION < 630U) || (QP_VERSION != ((QP_RELEASE^4294967295U) % 0x3E8U))
#error qpcpp version 6.3.0 or higher required
#endif

//$define${SMs::Calc} ########################################################
//${SMs::Calc} ...............................................................
//${SMs::Calc::Calc} .........................................................
Calc::Calc()
 : QHsm(Q_STATE_CAST(&Calc::initial))
{}

//${SMs::Calc::SM} ...........................................................
QP::QState Calc::initial(Calc * const me, QP::QEvt const * const e) {
    //${SMs::Calc::SM::initial}
    BSP_clear();
    (void)e; /* unused parameter */

    QS_FUN_DICTIONARY(&on);
    QS_FUN_DICTIONARY(&error);
    QS_FUN_DICTIONARY(&ready);
    QS_FUN_DICTIONARY(&result);
    QS_FUN_DICTIONARY(&begin);
    QS_FUN_DICTIONARY(&operand1);
    QS_FUN_DICTIONARY(&zero1);
    QS_FUN_DICTIONARY(&int1);
    QS_FUN_DICTIONARY(&frac1);
    QS_FUN_DICTIONARY(&negated1);
    QS_FUN_DICTIONARY(&opEntered);
    QS_FUN_DICTIONARY(&operand2);
    QS_FUN_DICTIONARY(&zero2);
    QS_FUN_DICTIONARY(&int2);
    QS_FUN_DICTIONARY(&frac2);
    QS_FUN_DICTIONARY(&negated2);
    QS_FUN_DICTIONARY(&final);

    return Q_TRAN(&on);
}
//${SMs::Calc::SM::on} .......................................................
QP::QState Calc::on(Calc * const me, QP::QEvt const * const e) {
    QP::QState status_;
    switch (e->sig) {
        //${SMs::Calc::SM::on}
        case Q_ENTRY_SIG: {
            BSP_message("on-ENTRY;");
            status_ = Q_HANDLED();
            break;
        }
        //${SMs::Calc::SM::on}
        case Q_EXIT_SIG: {
            BSP_message("on-EXIT;");
            status_ = Q_HANDLED();
            break;
        }
        //${SMs::Calc::SM::on::initial}
        case Q_INIT_SIG: {
            BSP_message("on-INIT;");
            status_ = Q_TRAN(&ready);
            break;
        }
        //${SMs::Calc::SM::on::C}
        case C_SIG: {
            BSP_clear();
            status_ = Q_TRAN(&on);
            break;
        }
        //${SMs::Calc::SM::on::OFF}
        case OFF_SIG: {
            status_ = Q_TRAN(&final);
            break;
        }
        default: {
            status_ = Q_SUPER(&top);
            break;
        }
    }
    return status_;
}
//${SMs::Calc::SM::on::error} ................................................
QP::QState Calc::error(Calc * const me, QP::QEvt const * const e) {
    QP::QState status_;
    switch (e->sig) {
        //${SMs::Calc::SM::on::error}
        case Q_ENTRY_SIG: {
            BSP_message("error-ENTRY;");
            status_ = Q_HANDLED();
            break;
        }
        //${SMs::Calc::SM::on::error}
        case Q_EXIT_SIG: {
            BSP_message("error-EXIT;");
            status_ = Q_HANDLED();
            break;
        }
        default: {
            status_ = Q_SUPER(&on);
            break;
        }
    }
    return status_;
}
//${SMs::Calc::SM::on::ready} ................................................
QP::QState Calc::ready(Calc * const me, QP::QEvt const * const e) {
    QP::QState status_;
    switch (e->sig) {
        //${SMs::Calc::SM::on::ready}
        case Q_ENTRY_SIG: {
            BSP_message("ready-ENTRY;");
            status_ = Q_HANDLED();
            break;
        }
        //${SMs::Calc::SM::on::ready}
        case Q_EXIT_SIG: {
            BSP_message("ready-EXIT;");
            status_ = Q_HANDLED();
            break;
        }
        //${SMs::Calc::SM::on::ready::initial}
        case Q_INIT_SIG: {
            BSP_message("ready-INIT;");
            status_ = Q_TRAN(&begin);
            break;
        }
        //${SMs::Calc::SM::on::ready::DIGIT_0}
        case DIGIT_0_SIG: {
            BSP_clear();
            status_ = Q_TRAN(&zero1);
            break;
        }
        //${SMs::Calc::SM::on::ready::DIGIT_1_9}
        case DIGIT_1_9_SIG: {
            BSP_clear();
            BSP_insert(Q_EVT_CAST(CalcEvt)->key_code);
            status_ = Q_TRAN(&int1);
            break;
        }
        //${SMs::Calc::SM::on::ready::POINT}
        case POINT_SIG: {
            BSP_clear();
            BSP_insert((int)'0');
            BSP_insert((int)'.');
            status_ = Q_TRAN(&frac1);
            break;
        }
        //${SMs::Calc::SM::on::ready::OPER}
        case OPER_SIG: {
            me->op1  = BSP_get_value();
            me->oper = Q_EVT_CAST(CalcEvt)->key_code;
            status_ = Q_TRAN(&opEntered);
            break;
        }
        default: {
            status_ = Q_SUPER(&on);
            break;
        }
    }
    return status_;
}
//${SMs::Calc::SM::on::ready::result} ........................................
QP::QState Calc::result(Calc * const me, QP::QEvt const * const e) {
    QP::QState status_;
    switch (e->sig) {
        //${SMs::Calc::SM::on::ready::result}
        case Q_ENTRY_SIG: {
            BSP_message("result-ENTRY;");
            status_ = Q_HANDLED();
            break;
        }
        //${SMs::Calc::SM::on::ready::result}
        case Q_EXIT_SIG: {
            BSP_message("result-EXIT;");
            status_ = Q_HANDLED();
            break;
        }
        default: {
            status_ = Q_SUPER(&ready);
            break;
        }
    }
    return status_;
}
//${SMs::Calc::SM::on::ready::begin} .........................................
QP::QState Calc::begin(Calc * const me, QP::QEvt const * const e) {
    QP::QState status_;
    switch (e->sig) {
        //${SMs::Calc::SM::on::ready::begin}
        case Q_ENTRY_SIG: {
            BSP_message("begin-ENTRY;");
            status_ = Q_HANDLED();
            break;
        }
        //${SMs::Calc::SM::on::ready::begin}
        case Q_EXIT_SIG: {
            BSP_message("begin-EXIT;");
            status_ = Q_HANDLED();
            break;
        }
        //${SMs::Calc::SM::on::ready::begin::OPER}
        case OPER_SIG: {
            //${SMs::Calc::SM::on::ready::begin::OPER::[e->key=='-']}
            if (Q_EVT_CAST(CalcEvt)->key_code == KEY_MINUS) {
                status_ = Q_TRAN(&negated1);
            }
            //${SMs::Calc::SM::on::ready::begin::OPER::[else]}
            else {
                status_ = Q_HANDLED();
            }
            break;
        }
        default: {
            status_ = Q_SUPER(&ready);
            break;
        }
    }
    return status_;
}
//${SMs::Calc::SM::on::operand1} .............................................
QP::QState Calc::operand1(Calc * const me, QP::QEvt const * const e) {
    QP::QState status_;
    switch (e->sig) {
        //${SMs::Calc::SM::on::operand1}
        case Q_ENTRY_SIG: {
            BSP_message("operand1-ENTRY;");
            status_ = Q_HANDLED();
            break;
        }
        //${SMs::Calc::SM::on::operand1}
        case Q_EXIT_SIG: {
            BSP_message("operand1-EXIT;");
            status_ = Q_HANDLED();
            break;
        }
        //${SMs::Calc::SM::on::operand1::CE}
        case CE_SIG: {
            BSP_clear();
            status_ = Q_TRAN(&begin);
            break;
        }
        //${SMs::Calc::SM::on::operand1::OPER}
        case OPER_SIG: {
            me->op1  = BSP_get_value();
            me->oper = Q_EVT_CAST(CalcEvt)->key_code;
            status_ = Q_TRAN(&opEntered);
            break;
        }
        //${SMs::Calc::SM::on::operand1::EQUALS}
        case EQUALS_SIG: {
            status_ = Q_TRAN(&result);
            break;
        }
        default: {
            status_ = Q_SUPER(&on);
            break;
        }
    }
    return status_;
}
//${SMs::Calc::SM::on::operand1::zero1} ......................................
QP::QState Calc::zero1(Calc * const me, QP::QEvt const * const e) {
    QP::QState status_;
    switch (e->sig) {
        //${SMs::Calc::SM::on::operand1::zero1}
        case Q_ENTRY_SIG: {
            BSP_message("zero1-ENTRY;");
            status_ = Q_HANDLED();
            break;
        }
        //${SMs::Calc::SM::on::operand1::zero1}
        case Q_EXIT_SIG: {
            BSP_message("zero1-EXIT;");
            status_ = Q_HANDLED();
            break;
        }
        //${SMs::Calc::SM::on::operand1::zero1::DIGIT_0}
        case DIGIT_0_SIG: {
            ;
            status_ = Q_HANDLED();
            break;
        }
        //${SMs::Calc::SM::on::operand1::zero1::DIGIT_1_9}
        case DIGIT_1_9_SIG: {
            BSP_insert(Q_EVT_CAST(CalcEvt)->key_code);
            status_ = Q_TRAN(&int1);
            break;
        }
        //${SMs::Calc::SM::on::operand1::zero1::POINT}
        case POINT_SIG: {
            BSP_insert((int)'0');
            BSP_insert((int)'.');
            status_ = Q_TRAN(&frac1);
            break;
        }
        default: {
            status_ = Q_SUPER(&operand1);
            break;
        }
    }
    return status_;
}
//${SMs::Calc::SM::on::operand1::int1} .......................................
QP::QState Calc::int1(Calc * const me, QP::QEvt const * const e) {
    QP::QState status_;
    switch (e->sig) {
        //${SMs::Calc::SM::on::operand1::int1}
        case Q_ENTRY_SIG: {
            BSP_message("int1-ENTRY;");
            status_ = Q_HANDLED();
            break;
        }
        //${SMs::Calc::SM::on::operand1::int1}
        case Q_EXIT_SIG: {
            BSP_message("int1-EXIT;");
            status_ = Q_HANDLED();
            break;
        }
        //${SMs::Calc::SM::on::operand1::int1::POINT}
        case POINT_SIG: {
            BSP_insert((int)'.');
            status_ = Q_TRAN(&frac1);
            break;
        }
        //${SMs::Calc::SM::on::operand1::int1::DIGIT_0, DIGIT_1_9}
        case DIGIT_0_SIG: // intentionally fall through
        case DIGIT_1_9_SIG: {
            BSP_insert(Q_EVT_CAST(CalcEvt)->key_code);
            status_ = Q_HANDLED();
            break;
        }
        default: {
            status_ = Q_SUPER(&operand1);
            break;
        }
    }
    return status_;
}
//${SMs::Calc::SM::on::operand1::frac1} ......................................
QP::QState Calc::frac1(Calc * const me, QP::QEvt const * const e) {
    QP::QState status_;
    switch (e->sig) {
        //${SMs::Calc::SM::on::operand1::frac1}
        case Q_ENTRY_SIG: {
            BSP_message("frac1-ENTRY;");
            status_ = Q_HANDLED();
            break;
        }
        //${SMs::Calc::SM::on::operand1::frac1}
        case Q_EXIT_SIG: {
            BSP_message("frac1-EXIT;");
            status_ = Q_HANDLED();
            break;
        }
        //${SMs::Calc::SM::on::operand1::frac1::POINT}
        case POINT_SIG: {
            ;
            status_ = Q_HANDLED();
            break;
        }
        //${SMs::Calc::SM::on::operand1::frac1::DIGIT_0, DIGIT_1_9}
        case DIGIT_0_SIG: // intentionally fall through
        case DIGIT_1_9_SIG: {
            BSP_insert(Q_EVT_CAST(CalcEvt)->key_code);
            status_ = Q_HANDLED();
            break;
        }
        default: {
            status_ = Q_SUPER(&operand1);
            break;
        }
    }
    return status_;
}
//${SMs::Calc::SM::on::operand1::negated1} ...................................
QP::QState Calc::negated1(Calc * const me, QP::QEvt const * const e) {
    QP::QState status_;
    switch (e->sig) {
        //${SMs::Calc::SM::on::operand1::negated1}
        case Q_ENTRY_SIG: {
            BSP_message("negated1-ENTRY;");
            BSP_negate();
            status_ = Q_HANDLED();
            break;
        }
        //${SMs::Calc::SM::on::operand1::negated1}
        case Q_EXIT_SIG: {
            BSP_message("negated1-EXIT;");
            status_ = Q_HANDLED();
            break;
        }
        //${SMs::Calc::SM::on::operand1::negated1::DIGIT_0}
        case DIGIT_0_SIG: {
            BSP_insert(Q_EVT_CAST(CalcEvt)->key_code);
            status_ = Q_TRAN(&zero1);
            break;
        }
        //${SMs::Calc::SM::on::operand1::negated1::DIGIT_1_9}
        case DIGIT_1_9_SIG: {
            BSP_insert(Q_EVT_CAST(CalcEvt)->key_code);
            status_ = Q_TRAN(&int1);
            break;
        }
        //${SMs::Calc::SM::on::operand1::negated1::POINT}
        case POINT_SIG: {
            BSP_insert(Q_EVT_CAST(CalcEvt)->key_code);
            status_ = Q_TRAN(&frac1);
            break;
        }
        //${SMs::Calc::SM::on::operand1::negated1::OPER}
        case OPER_SIG: {
            //${SMs::Calc::SM::on::operand1::negated1::OPER::[e->key=='-']}
            if (Q_EVT_CAST(CalcEvt)->key_code == KEY_MINUS) {
                ;
                status_ = Q_HANDLED();
            }
            //${SMs::Calc::SM::on::operand1::negated1::OPER::[else]}
            else {
                status_ = Q_HANDLED();
            }
            break;
        }
        default: {
            status_ = Q_SUPER(&operand1);
            break;
        }
    }
    return status_;
}
//${SMs::Calc::SM::on::opEntered} ............................................
QP::QState Calc::opEntered(Calc * const me, QP::QEvt const * const e) {
    QP::QState status_;
    switch (e->sig) {
        //${SMs::Calc::SM::on::opEntered}
        case Q_ENTRY_SIG: {
            BSP_message("opEntered-ENTRY;");
            status_ = Q_HANDLED();
            break;
        }
        //${SMs::Calc::SM::on::opEntered}
        case Q_EXIT_SIG: {
            BSP_message("opEntered-EXIT;");
            status_ = Q_HANDLED();
            break;
        }
        //${SMs::Calc::SM::on::opEntered::DIGIT_0}
        case DIGIT_0_SIG: {
            BSP_clear();
            status_ = Q_TRAN(&zero2);
            break;
        }
        //${SMs::Calc::SM::on::opEntered::DIGIT_1_9}
        case DIGIT_1_9_SIG: {
            BSP_clear();
            BSP_insert(Q_EVT_CAST(CalcEvt)->key_code);
            status_ = Q_TRAN(&int2);
            break;
        }
        //${SMs::Calc::SM::on::opEntered::POINT}
        case POINT_SIG: {
            BSP_clear();
            BSP_insert((int)'0');
            BSP_insert((int)'.');
            status_ = Q_TRAN(&frac2);
            break;
        }
        //${SMs::Calc::SM::on::opEntered::OPER}
        case OPER_SIG: {
            //${SMs::Calc::SM::on::opEntered::OPER::[e->key=='-']}
            if (Q_EVT_CAST(CalcEvt)->key_code == KEY_MINUS) {
                status_ = Q_TRAN(&negated2);
            }
            //${SMs::Calc::SM::on::opEntered::OPER::[else]}
            else {
                status_ = Q_HANDLED();
            }
            break;
        }
        default: {
            status_ = Q_SUPER(&on);
            break;
        }
    }
    return status_;
}
//${SMs::Calc::SM::on::operand2} .............................................
QP::QState Calc::operand2(Calc * const me, QP::QEvt const * const e) {
    QP::QState status_;
    switch (e->sig) {
        //${SMs::Calc::SM::on::operand2}
        case Q_ENTRY_SIG: {
            BSP_message("operand2-ENTRY;");
            status_ = Q_HANDLED();
            break;
        }
        //${SMs::Calc::SM::on::operand2}
        case Q_EXIT_SIG: {
            BSP_message("operand2-EXIT;");
            status_ = Q_HANDLED();
            break;
        }
        //${SMs::Calc::SM::on::operand2::CE}
        case CE_SIG: {
            BSP_clear();
            status_ = Q_TRAN(&opEntered);
            break;
        }
        //${SMs::Calc::SM::on::operand2::EQUALS}
        case EQUALS_SIG: {
            //${SMs::Calc::SM::on::operand2::EQUALS::[BSP_eval()]}
            if (BSP_eval(me->op1, me->oper, BSP_get_value())) {
                status_ = Q_TRAN(&result);
            }
            //${SMs::Calc::SM::on::operand2::EQUALS::[else]}
            else {
                status_ = Q_TRAN(&error);
            }
            break;
        }
        //${SMs::Calc::SM::on::operand2::OPER}
        case OPER_SIG: {
            //${SMs::Calc::SM::on::operand2::OPER::[BSP_eval()]}
            if (BSP_eval(me->op1, me->oper, BSP_get_value())) {
                status_ = Q_TRAN(&opEntered);
            }
            //${SMs::Calc::SM::on::operand2::OPER::[else]}
            else {
                status_ = Q_TRAN(&error);
            }
            break;
        }
        default: {
            status_ = Q_SUPER(&on);
            break;
        }
    }
    return status_;
}
//${SMs::Calc::SM::on::operand2::zero2} ......................................
QP::QState Calc::zero2(Calc * const me, QP::QEvt const * const e) {
    QP::QState status_;
    switch (e->sig) {
        //${SMs::Calc::SM::on::operand2::zero2}
        case Q_ENTRY_SIG: {
            BSP_message("zero2-ENTRY;");
            status_ = Q_HANDLED();
            break;
        }
        //${SMs::Calc::SM::on::operand2::zero2}
        case Q_EXIT_SIG: {
            BSP_message("zero2-EXIT;");
            status_ = Q_HANDLED();
            break;
        }
        //${SMs::Calc::SM::on::operand2::zero2::DIGIT_0}
        case DIGIT_0_SIG: {
            ;
            status_ = Q_HANDLED();
            break;
        }
        //${SMs::Calc::SM::on::operand2::zero2::DIGIT_1_9}
        case DIGIT_1_9_SIG: {
            BSP_insert(Q_EVT_CAST(CalcEvt)->key_code);
            status_ = Q_TRAN(&int2);
            break;
        }
        //${SMs::Calc::SM::on::operand2::zero2::POINT}
        case POINT_SIG: {
            BSP_insert((int)'0');
            BSP_insert((int)'.');
            status_ = Q_TRAN(&frac2);
            break;
        }
        default: {
            status_ = Q_SUPER(&operand2);
            break;
        }
    }
    return status_;
}
//${SMs::Calc::SM::on::operand2::int2} .......................................
QP::QState Calc::int2(Calc * const me, QP::QEvt const * const e) {
    QP::QState status_;
    switch (e->sig) {
        //${SMs::Calc::SM::on::operand2::int2}
        case Q_ENTRY_SIG: {
            BSP_message("int2-ENTRY;");
            status_ = Q_HANDLED();
            break;
        }
        //${SMs::Calc::SM::on::operand2::int2}
        case Q_EXIT_SIG: {
            BSP_message("int2-EXIT;");
            status_ = Q_HANDLED();
            break;
        }
        //${SMs::Calc::SM::on::operand2::int2::POINT}
        case POINT_SIG: {
            BSP_insert((int)'.');
            status_ = Q_TRAN(&frac2);
            break;
        }
        //${SMs::Calc::SM::on::operand2::int2::DIGIT_0, DIGIT_1_9}
        case DIGIT_0_SIG: // intentionally fall through
        case DIGIT_1_9_SIG: {
            BSP_insert(Q_EVT_CAST(CalcEvt)->key_code);
            status_ = Q_HANDLED();
            break;
        }
        default: {
            status_ = Q_SUPER(&operand2);
            break;
        }
    }
    return status_;
}
//${SMs::Calc::SM::on::operand2::frac2} ......................................
QP::QState Calc::frac2(Calc * const me, QP::QEvt const * const e) {
    QP::QState status_;
    switch (e->sig) {
        //${SMs::Calc::SM::on::operand2::frac2}
        case Q_ENTRY_SIG: {
            BSP_message("frac2-ENTRY;");
            status_ = Q_HANDLED();
            break;
        }
        //${SMs::Calc::SM::on::operand2::frac2}
        case Q_EXIT_SIG: {
            BSP_message("frac2-EXIT;");
            status_ = Q_HANDLED();
            break;
        }
        //${SMs::Calc::SM::on::operand2::frac2::POINT}
        case POINT_SIG: {
            ;
            status_ = Q_HANDLED();
            break;
        }
        //${SMs::Calc::SM::on::operand2::frac2::DIGIT_0, DIGIT_1_9}
        case DIGIT_0_SIG: // intentionally fall through
        case DIGIT_1_9_SIG: {
            BSP_insert(Q_EVT_CAST(CalcEvt)->key_code);
            status_ = Q_HANDLED();
            break;
        }
        default: {
            status_ = Q_SUPER(&operand2);
            break;
        }
    }
    return status_;
}
//${SMs::Calc::SM::on::operand2::negated2} ...................................
QP::QState Calc::negated2(Calc * const me, QP::QEvt const * const e) {
    QP::QState status_;
    switch (e->sig) {
        //${SMs::Calc::SM::on::operand2::negated2}
        case Q_ENTRY_SIG: {
            BSP_message("negated2-ENTRY;");
            BSP_negate();
            status_ = Q_HANDLED();
            break;
        }
        //${SMs::Calc::SM::on::operand2::negated2}
        case Q_EXIT_SIG: {
            BSP_message("negated2-EXIT;");
            status_ = Q_HANDLED();
            break;
        }
        //${SMs::Calc::SM::on::operand2::negated2::DIGIT_0}
        case DIGIT_0_SIG: {
            BSP_insert(Q_EVT_CAST(CalcEvt)->key_code);
            status_ = Q_TRAN(&zero2);
            break;
        }
        //${SMs::Calc::SM::on::operand2::negated2::DIGIT_1_9}
        case DIGIT_1_9_SIG: {
            BSP_insert(Q_EVT_CAST(CalcEvt)->key_code);
            status_ = Q_TRAN(&int2);
            break;
        }
        //${SMs::Calc::SM::on::operand2::negated2::POINT}
        case POINT_SIG: {
            BSP_insert(Q_EVT_CAST(CalcEvt)->key_code);
            status_ = Q_TRAN(&frac2);
            break;
        }
        //${SMs::Calc::SM::on::operand2::negated2::OPER}
        case OPER_SIG: {
            //${SMs::Calc::SM::on::operand2::negated2::OPER::[e->key=='-']}
            if (Q_EVT_CAST(CalcEvt)->key_code == KEY_MINUS) {
                ;
                status_ = Q_HANDLED();
            }
            //${SMs::Calc::SM::on::operand2::negated2::OPER::[else]}
            else {
                status_ = Q_HANDLED();
            }
            break;
        }
        default: {
            status_ = Q_SUPER(&operand2);
            break;
        }
    }
    return status_;
}
//${SMs::Calc::SM::final} ....................................................
QP::QState Calc::final(Calc * const me, QP::QEvt const * const e) {
    QP::QState status_;
    switch (e->sig) {
        //${SMs::Calc::SM::final}
        case Q_ENTRY_SIG: {
            BSP_message("final-ENTRY;");
            BSP_exit();
            status_ = Q_HANDLED();
            break;
        }
        default: {
            status_ = Q_SUPER(&top);
            break;
        }
    }
    return status_;
}
//$enddef${SMs::Calc} ########################################################

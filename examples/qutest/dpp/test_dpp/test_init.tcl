# test-script for QUTest unit testing harness
# see https://www.state-machine.com/qtools/qutest.html

# preamble...
proc on_reset {} {
    expect_pause
    glb_filter ON
    continue
    expect "%timestamp AO-Subsc Obj=AO_Philo<0>,Sig=EAT_SIG"
    expect "%timestamp AO-Subsc Obj=AO_Philo<0>,Sig=TEST_SIG"
    expect "===RTC===> St-Init  Obj=AO_Philo<0>,State=QP::QHsm::top->thinking"
    expect "%timestamp BSP_CALL BSP::random *"
    expect "%timestamp TE0-Arm  Obj=l_philo<0>.m_timeEvt,AO=AO_Philo<0>,Tim=*,Int=0"
    expect "===RTC===> St-Entry Obj=AO_Philo<0>,State=thinking"
    expect "%timestamp Init===> Obj=AO_Philo<0>,State=thinking"
    expect "%timestamp AO-Subsc Obj=AO_Philo<1>,Sig=EAT_SIG"
    expect "%timestamp AO-Subsc Obj=AO_Philo<1>,Sig=TEST_SIG"
    expect "===RTC===> St-Init  Obj=AO_Philo<1>,State=QP::QHsm::top->thinking"
    expect "%timestamp BSP_CALL BSP::random *"
    expect "%timestamp TE0-Arm  Obj=l_philo<1>.m_timeEvt,AO=AO_Philo<1>,Tim=*,Int=0"
    expect "===RTC===> St-Entry Obj=AO_Philo<1>,State=thinking"
    expect "%timestamp Init===> Obj=AO_Philo<1>,State=thinking"
    expect "%timestamp AO-Subsc Obj=AO_Philo<2>,Sig=EAT_SIG"
    expect "%timestamp AO-Subsc Obj=AO_Philo<2>,Sig=TEST_SIG"
    expect "===RTC===> St-Init  Obj=AO_Philo<2>,State=QP::QHsm::top->thinking"
    expect "%timestamp BSP_CALL BSP::random *"
    expect "%timestamp TE0-Arm  Obj=l_philo<2>.m_timeEvt,AO=AO_Philo<2>,Tim=*,Int=0"
    expect "===RTC===> St-Entry Obj=AO_Philo<2>,State=thinking"
    expect "%timestamp Init===> Obj=AO_Philo<2>,State=thinking"
    expect "%timestamp AO-Subsc Obj=AO_Philo<3>,Sig=EAT_SIG"
    expect "%timestamp AO-Subsc Obj=AO_Philo<3>,Sig=TEST_SIG"
    expect "===RTC===> St-Init  Obj=AO_Philo<3>,State=QP::QHsm::top->thinking"
    expect "%timestamp BSP_CALL BSP::random *"
    expect "%timestamp TE0-Arm  Obj=l_philo<3>.m_timeEvt,AO=AO_Philo<3>,Tim=*,Int=0"
    expect "===RTC===> St-Entry Obj=AO_Philo<3>,State=thinking"
    expect "%timestamp Init===> Obj=AO_Philo<3>,State=thinking"
    expect "%timestamp AO-Subsc Obj=AO_Philo<4>,Sig=EAT_SIG"
    expect "%timestamp AO-Subsc Obj=AO_Philo<4>,Sig=TEST_SIG"
    expect "===RTC===> St-Init  Obj=AO_Philo<4>,State=QP::QHsm::top->thinking"
    expect "%timestamp BSP_CALL BSP::random *"
    expect "%timestamp TE0-Arm  Obj=l_philo<4>.m_timeEvt,AO=AO_Philo<4>,Tim=*,Int=0"
    expect "===RTC===> St-Entry Obj=AO_Philo<4>,State=thinking"
    expect "%timestamp Init===> Obj=AO_Philo<4>,State=thinking"
    expect "%timestamp AO-Subsc Obj=AO_Table,Sig=DONE_SIG"
    expect "%timestamp AO-Subsc Obj=AO_Table,Sig=PAUSE_SIG"
    expect "%timestamp AO-Subsc Obj=AO_Table,Sig=SERVE_SIG"
    expect "%timestamp AO-Subsc Obj=AO_Table,Sig=TEST_SIG"
    expect "%timestamp BSP_CALL BSP::displayPhilStat 0 thinking"
    expect "%timestamp BSP_CALL BSP::displayPhilStat 1 thinking"
    expect "%timestamp BSP_CALL BSP::displayPhilStat 2 thinking"
    expect "%timestamp BSP_CALL BSP::displayPhilStat 3 thinking"
    expect "%timestamp BSP_CALL BSP::displayPhilStat 4 thinking"
    expect "===RTC===> St-Init  Obj=AO_Table,State=QP::QHsm::top->serving"
    expect "===RTC===> St-Entry Obj=AO_Table,State=serving"
    expect "%timestamp Init===> Obj=AO_Table,State=serving"
}

# tests...
test "DPP init"

# the end
end

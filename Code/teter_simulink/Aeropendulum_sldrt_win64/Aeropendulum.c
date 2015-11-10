/*
 * Aeropendulum.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Aeropendulum".
 *
 * Model version              : 1.173
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Thu Nov 05 17:35:39 2015
 *
 * Target selection: rtwin.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Aeropendulum.h"
#include "Aeropendulum_private.h"
#include "Aeropendulum_dt.h"

/* options for Simulink Desktop Real-Time board 0 */
static double RTWinBoardOptions0[] = {
  9600.0,
  8.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
};

/* list of Simulink Desktop Real-Time timers */
const int RTWinTimerCount = 1;
const double RTWinTimers[2] = {
  0.01, 0.0,
};

/* list of Simulink Desktop Real-Time boards */
const int RTWinBoardCount = 1;
RTWINBOARD RTWinBoards[1] = {
  { "Standard_Devices/Serial_Port", 4U, 8, RTWinBoardOptions0 },
};

/* Block signals (auto storage) */
B_Aeropendulum_T Aeropendulum_B;

/* Block states (auto storage) */
DW_Aeropendulum_T Aeropendulum_DW;

/* Real-time model */
RT_MODEL_Aeropendulum_T Aeropendulum_M_;
RT_MODEL_Aeropendulum_T *const Aeropendulum_M = &Aeropendulum_M_;

/* Model output function */
void Aeropendulum_output(void)
{
  real_T u0;

  /* S-Function Block: <S17>/Packet Input */
  {
    uint8_T indata[2U];
    int status = RTBIO_DriverIO(0, STREAMINPUT, IOREAD, 2U,
      &Aeropendulum_P.PacketInput_PacketID, (double*) indata, NULL);
    Aeropendulum_B.PacketInput_o2 = status & 0x1;/* Data Ready port */
    if (status & 0x1) {
      RTWin_ANYTYPEPTR indp;
      indp.p_uint8_T = indata;
      Aeropendulum_B.PacketInput_o1 = *indp.p_uint16_T++;
    }
  }

  /* DiscretePulseGenerator: '<S17>/128 Query' */
  Aeropendulum_B.u8Query = (Aeropendulum_DW.clockTickCounter <
    Aeropendulum_P.u8Query_Duty) && (Aeropendulum_DW.clockTickCounter >= 0) ?
    Aeropendulum_P.u8Query_Amp : 0.0;
  if (Aeropendulum_DW.clockTickCounter >= Aeropendulum_P.u8Query_Period - 1.0) {
    Aeropendulum_DW.clockTickCounter = 0;
  } else {
    Aeropendulum_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<S17>/128 Query' */
  /* S-Function Block: <S17>/Packet Output */

  /* no code required */

  /* S-Function Block: <S6>/Packet Output */

  /* no code required */

  /* DataTypeConversion: '<S16>/unit16 -> double' */
  Aeropendulum_B.unit16double = Aeropendulum_B.PacketInput_o1;

  /* Clock: '<S18>/Clock' */
  Aeropendulum_B.Clock = Aeropendulum_M->Timing.t[0];

  /* MATLAB Function: '<S18>/Switch & Memory' incorporates:
   *  Constant: '<S18>/Tinit'
   */
  /* MATLAB Function 'Pendulum I/O  (Plant)/Calibrate Reading/Initial Reading/Switch & Memory': '<S19>:1' */
  /* memorize initial position */
  /* if time is less than time to acquire signal, save. */
  if ((!Aeropendulum_DW.xy_not_empty) || (Aeropendulum_B.Clock <
       Aeropendulum_P.Tinit_Value)) {
    /* '<S19>:1:8' */
    /* '<S19>:1:10' */
    Aeropendulum_DW.xy = Aeropendulum_B.PacketInput_o1;
    Aeropendulum_DW.xy_not_empty = true;
  }

  /* Gain: '<S16>/K_pot' incorporates:
   *  MATLAB Function: '<S18>/Switch & Memory'
   *  Sum: '<S16>/Calibrate Reading'
   */
  /* return value */
  /* '<S19>:1:15' */
  Aeropendulum_B.K_pot = (Aeropendulum_B.unit16double - (real_T)
    Aeropendulum_DW.xy) * Aeropendulum_P.K_pot_Gain;

  /* Constant: '<S1>/Constant3' */
  Aeropendulum_B.Constant3 = Aeropendulum_P.Constant3_Value;

  /* MultiPortSwitch: '<Root>/Multiport Switch' incorporates:
   *  Constant: '<Root>/Controller Select'
   *  Constant: '<Root>/Open Loop Duty Cycle'
   */
  switch ((int32_T)Aeropendulum_P.ControllerSelect_Value) {
   case 1:
    Aeropendulum_B.MultiportSwitch = Aeropendulum_P.OpenLoopDutyCycle_Value;
    break;

   case 2:
    /* Sum: '<S7>/Sum3' incorporates:
     *  Constant: '<S1>/Constant1'
     *  Constant: '<S1>/Constant2'
     *  Constant: '<S1>/S2'
     *  Gain: '<S7>/Deg->Rad'
     *  Product: '<S7>/Product'
     *  Product: '<S7>/Product1'
     *  Sum: '<S7>/Sum1'
     *  Sum: '<S7>/Sum2'
     *  Trigonometry: '<S7>/Trigonometric Function'
     */
    u0 = (sin(Aeropendulum_P.DegRad_Gain_k * Aeropendulum_B.K_pot) *
          Aeropendulum_P.S2_Value + Aeropendulum_P.Constant2_Value) +
      (Aeropendulum_B.Constant3 - Aeropendulum_B.K_pot) *
      Aeropendulum_P.Constant1_Value;

    /* Saturate: '<S7>/Saturation' */
    if (u0 > Aeropendulum_P.Saturation_UpperSat_a) {
      Aeropendulum_B.MultiportSwitch = Aeropendulum_P.Saturation_UpperSat_a;
    } else if (u0 < Aeropendulum_P.Saturation_LowerSat_b) {
      Aeropendulum_B.MultiportSwitch = Aeropendulum_P.Saturation_LowerSat_b;
    } else {
      Aeropendulum_B.MultiportSwitch = u0;
    }

    /* End of Saturate: '<S7>/Saturation' */
    break;

   case 3:
    /* Sum: '<S3>/Sum3' incorporates:
     *  Constant: '<S1>/Constant2'
     *  Constant: '<S1>/S2'
     *  Gain: '<S9>/Deg->Rad'
     *  Product: '<S9>/Product'
     *  StateSpace: '<S8>/Internal'
     *  Sum: '<S3>/Sum1'
     *  Sum: '<S3>/Sum2'
     *  Trigonometry: '<S9>/Trigonometric Function'
     */
    u0 = (sin(Aeropendulum_P.DegRad_Gain_g * Aeropendulum_B.K_pot) *
          Aeropendulum_P.S2_Value + Aeropendulum_P.Constant2_Value) +
      (Aeropendulum_B.Constant3 - Aeropendulum_B.K_pot) *
      Aeropendulum_P.Internal_D;

    /* Saturate: '<S3>/Saturation' */
    if (u0 > Aeropendulum_P.Saturation_UpperSat_i) {
      Aeropendulum_B.MultiportSwitch = Aeropendulum_P.Saturation_UpperSat_i;
    } else if (u0 < Aeropendulum_P.Saturation_LowerSat_e) {
      Aeropendulum_B.MultiportSwitch = Aeropendulum_P.Saturation_LowerSat_e;
    } else {
      Aeropendulum_B.MultiportSwitch = u0;
    }

    /* End of Saturate: '<S3>/Saturation' */
    break;

   default:
    /* Sum: '<S4>/Sum4' incorporates:
     *  Constant: '<S1>/Constant2'
     *  Constant: '<S1>/S2'
     *  Gain: '<S13>/Deg->Rad'
     *  Product: '<S13>/Product'
     *  StateSpace: '<S12>/Internal'
     *  Sum: '<S4>/Sum1'
     *  Sum: '<S4>/Sum2'
     *  Trigonometry: '<S13>/Trigonometric Function'
     */
    u0 = (sin(Aeropendulum_P.DegRad_Gain * Aeropendulum_B.K_pot) *
          Aeropendulum_P.S2_Value + Aeropendulum_P.Constant2_Value) +
      (Aeropendulum_B.Constant3 - Aeropendulum_B.K_pot) *
      Aeropendulum_P.Internal_D_l;

    /* Saturate: '<S4>/Saturation' */
    if (u0 > Aeropendulum_P.Saturation_UpperSat) {
      Aeropendulum_B.MultiportSwitch = Aeropendulum_P.Saturation_UpperSat;
    } else if (u0 < Aeropendulum_P.Saturation_LowerSat) {
      Aeropendulum_B.MultiportSwitch = Aeropendulum_P.Saturation_LowerSat;
    } else {
      Aeropendulum_B.MultiportSwitch = u0;
    }

    /* End of Saturate: '<S4>/Saturation' */
    break;
  }

  /* End of MultiPortSwitch: '<Root>/Multiport Switch' */
}

/* Model update function */
void Aeropendulum_update(void)
{
  /* S-Function Block: <S17>/Packet Output */
  {
    uint8_T outdata[1U];
    RTWin_ANYTYPEPTR outdp;
    outdp.p_uint8_T = outdata;

    {
      real_T pktin = Aeropendulum_B.u8Query;
      int8_T pktout = pktin>=MAX_int8_T ? MAX_int8_T : (pktin<=MIN_int8_T ?
        MIN_int8_T : (int8_T) pktin);
      *outdp.p_int8_T++ = pktout;
    }

    RTBIO_DriverIO(0, STREAMOUTPUT, IOWRITE, 1U,
                   &Aeropendulum_P.PacketOutput_PacketID, (double*) outdata,
                   NULL);
  }

  /* S-Function Block: <S6>/Packet Output */
  {
    uint8_T outdata[1U];
    RTWin_ANYTYPEPTR outdp;
    outdp.p_uint8_T = outdata;

    {
      real_T pktin = Aeropendulum_B.MultiportSwitch;
      int8_T pktout = pktin>=MAX_int8_T ? MAX_int8_T : (pktin<=MIN_int8_T ?
        MIN_int8_T : (int8_T) pktin);
      *outdp.p_int8_T++ = pktout;
    }

    RTBIO_DriverIO(0, STREAMOUTPUT, IOWRITE, 1U,
                   &Aeropendulum_P.PacketOutput_PacketID_f, (double*) outdata,
                   NULL);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Aeropendulum_M->Timing.clockTick0)) {
    ++Aeropendulum_M->Timing.clockTickH0;
  }

  Aeropendulum_M->Timing.t[0] = Aeropendulum_M->Timing.clockTick0 *
    Aeropendulum_M->Timing.stepSize0 + Aeropendulum_M->Timing.clockTickH0 *
    Aeropendulum_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++Aeropendulum_M->Timing.clockTick1)) {
      ++Aeropendulum_M->Timing.clockTickH1;
    }

    Aeropendulum_M->Timing.t[1] = Aeropendulum_M->Timing.clockTick1 *
      Aeropendulum_M->Timing.stepSize1 + Aeropendulum_M->Timing.clockTickH1 *
      Aeropendulum_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
void Aeropendulum_initialize(void)
{
  /* Start for DiscretePulseGenerator: '<S17>/128 Query' */
  Aeropendulum_DW.clockTickCounter = 0;

  /* S-Function Block: <S17>/Packet Output */
  /* no initial value should be set */

  /* S-Function Block: <S6>/Packet Output */
  /* no initial value should be set */

  /* InitializeConditions for MATLAB Function: '<S18>/Switch & Memory' */
  Aeropendulum_DW.xy_not_empty = false;
}

/* Model terminate function */
void Aeropendulum_terminate(void)
{
  /* S-Function Block: <S17>/Packet Output */
  /* no initial value should be set */

  /* S-Function Block: <S6>/Packet Output */
  /* no initial value should be set */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  Aeropendulum_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Aeropendulum_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  Aeropendulum_initialize();
}

void MdlTerminate(void)
{
  Aeropendulum_terminate();
}

/* Registration function */
RT_MODEL_Aeropendulum_T *Aeropendulum(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Aeropendulum_M, 0,
                sizeof(RT_MODEL_Aeropendulum_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Aeropendulum_M->solverInfo,
                          &Aeropendulum_M->Timing.simTimeStep);
    rtsiSetTPtr(&Aeropendulum_M->solverInfo, &rtmGetTPtr(Aeropendulum_M));
    rtsiSetStepSizePtr(&Aeropendulum_M->solverInfo,
                       &Aeropendulum_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Aeropendulum_M->solverInfo, (&rtmGetErrorStatus
      (Aeropendulum_M)));
    rtsiSetRTModelPtr(&Aeropendulum_M->solverInfo, Aeropendulum_M);
  }

  rtsiSetSimTimeStep(&Aeropendulum_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&Aeropendulum_M->solverInfo,"FixedStepDiscrete");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Aeropendulum_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    Aeropendulum_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Aeropendulum_M->Timing.sampleTimes =
      (&Aeropendulum_M->Timing.sampleTimesArray[0]);
    Aeropendulum_M->Timing.offsetTimes =
      (&Aeropendulum_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Aeropendulum_M->Timing.sampleTimes[0] = (0.0);
    Aeropendulum_M->Timing.sampleTimes[1] = (0.01);

    /* task offsets */
    Aeropendulum_M->Timing.offsetTimes[0] = (0.0);
    Aeropendulum_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(Aeropendulum_M, &Aeropendulum_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Aeropendulum_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    Aeropendulum_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Aeropendulum_M, 60.0);
  Aeropendulum_M->Timing.stepSize0 = 0.01;
  Aeropendulum_M->Timing.stepSize1 = 0.01;

  /* External mode info */
  Aeropendulum_M->Sizes.checksums[0] = (1364114056U);
  Aeropendulum_M->Sizes.checksums[1] = (1767644293U);
  Aeropendulum_M->Sizes.checksums[2] = (2419654480U);
  Aeropendulum_M->Sizes.checksums[3] = (2397139369U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[5];
    Aeropendulum_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Aeropendulum_M->extModeInfo,
      &Aeropendulum_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Aeropendulum_M->extModeInfo,
                        Aeropendulum_M->Sizes.checksums);
    rteiSetTPtr(Aeropendulum_M->extModeInfo, rtmGetTPtr(Aeropendulum_M));
  }

  Aeropendulum_M->solverInfoPtr = (&Aeropendulum_M->solverInfo);
  Aeropendulum_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&Aeropendulum_M->solverInfo, 0.01);
  rtsiSetSolverMode(&Aeropendulum_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Aeropendulum_M->ModelData.blockIO = ((void *) &Aeropendulum_B);
  (void) memset(((void *) &Aeropendulum_B), 0,
                sizeof(B_Aeropendulum_T));

  /* parameters */
  Aeropendulum_M->ModelData.defaultParam = ((real_T *)&Aeropendulum_P);

  /* states (dwork) */
  Aeropendulum_M->ModelData.dwork = ((void *) &Aeropendulum_DW);
  (void) memset((void *)&Aeropendulum_DW, 0,
                sizeof(DW_Aeropendulum_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Aeropendulum_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize Sizes */
  Aeropendulum_M->Sizes.numContStates = (0);/* Number of continuous states */
  Aeropendulum_M->Sizes.numY = (0);    /* Number of model outputs */
  Aeropendulum_M->Sizes.numU = (0);    /* Number of model inputs */
  Aeropendulum_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Aeropendulum_M->Sizes.numSampTimes = (2);/* Number of sample times */
  Aeropendulum_M->Sizes.numBlocks = (51);/* Number of blocks */
  Aeropendulum_M->Sizes.numBlockIO = (10);/* Number of block outputs */
  Aeropendulum_M->Sizes.numBlockPrms = (32);/* Sum of parameter "widths" */
  return Aeropendulum_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/

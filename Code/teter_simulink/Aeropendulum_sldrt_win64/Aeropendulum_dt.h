/*
 * Aeropendulum_dt.h
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

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&Aeropendulum_B.u8Query), 0, 0, 6 },

  { (char_T *)(&Aeropendulum_B.PacketInput_o1), 5, 0, 1 },

  { (char_T *)(&Aeropendulum_B.PacketInput_o2), 8, 0, 1 }
  ,

  { (char_T *)(&Aeropendulum_DW.PacketInput_PWORK), 11, 0, 11 },

  { (char_T *)(&Aeropendulum_DW.clockTickCounter), 6, 0, 1 },

  { (char_T *)(&Aeropendulum_DW.xy), 5, 0, 1 },

  { (char_T *)(&Aeropendulum_DW.xy_not_empty), 8, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  7U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&Aeropendulum_P.PacketInput_MaxMissedTicks), 0, 0, 6 },

  { (char_T *)(&Aeropendulum_P.PacketInput_PacketID), 6, 0, 3 },

  { (char_T *)(&Aeropendulum_P.DegRad_Gain), 0, 0, 23 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  3U,
  rtPTransitions
};

/* [EOF] Aeropendulum_dt.h */

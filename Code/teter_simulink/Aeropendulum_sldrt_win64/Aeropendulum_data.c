/*
 * Aeropendulum_data.c
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

/* Block parameters (auto storage) */
P_Aeropendulum_T Aeropendulum_P = {
  10.0,                                /* Mask Parameter: PacketInput_MaxMissedTicks
                                        * Referenced by: '<S17>/Packet Input'
                                        */
  10.0,                                /* Mask Parameter: PacketOutput_MaxMissedTicks
                                        * Referenced by: '<S17>/Packet Output'
                                        */
  10.0,                                /* Mask Parameter: PacketOutput_MaxMissedTicks_e
                                        * Referenced by: '<S6>/Packet Output'
                                        */
  0.0,                                 /* Mask Parameter: PacketInput_YieldWhenWaiting
                                        * Referenced by: '<S17>/Packet Input'
                                        */
  0.0,                                 /* Mask Parameter: PacketOutput_YieldWhenWaiting
                                        * Referenced by: '<S17>/Packet Output'
                                        */
  0.0,                                 /* Mask Parameter: PacketOutput_YieldWhenWaiting_b
                                        * Referenced by: '<S6>/Packet Output'
                                        */
  1,                                   /* Mask Parameter: PacketInput_PacketID
                                        * Referenced by: '<S17>/Packet Input'
                                        */
  1,                                   /* Mask Parameter: PacketOutput_PacketID
                                        * Referenced by: '<S17>/Packet Output'
                                        */
  1,                                   /* Mask Parameter: PacketOutput_PacketID_f
                                        * Referenced by: '<S6>/Packet Output'
                                        */
  0.017453292519943295,                /* Expression: pi()/180
                                        * Referenced by: '<S13>/Deg->Rad'
                                        */
  127.0,                               /* Expression: 127
                                        * Referenced by: '<S4>/Saturation'
                                        */
  -127.0,                              /* Expression: -127
                                        * Referenced by: '<S4>/Saturation'
                                        */
  0.017453292519943295,                /* Expression: pi()/180
                                        * Referenced by: '<S9>/Deg->Rad'
                                        */
  127.0,                               /* Expression: 127
                                        * Referenced by: '<S3>/Saturation'
                                        */
  -127.0,                              /* Expression: -127
                                        * Referenced by: '<S3>/Saturation'
                                        */
  0.017453292519943295,                /* Expression: pi()/180
                                        * Referenced by: '<S7>/Deg->Rad'
                                        */
  127.0,                               /* Expression: 127
                                        * Referenced by: '<S7>/Saturation'
                                        */
  -127.0,                              /* Expression: -127
                                        * Referenced by: '<S7>/Saturation'
                                        */
  128.0,                               /* Expression: 128
                                        * Referenced by: '<S17>/128 Query'
                                        */
  2.0,                                 /* Computed Parameter: u8Query_Period
                                        * Referenced by: '<S17>/128 Query'
                                        */
  1.0,                                 /* Computed Parameter: u8Query_Duty
                                        * Referenced by: '<S17>/128 Query'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S17>/128 Query'
                                        */
  0.1,                                 /* Expression: .1
                                        * Referenced by: '<S18>/Tinit'
                                        */
  0.083028083028083025,                /* Expression: 340/4095
                                        * Referenced by: '<S16>/K_pot'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Controller Select'
                                        */
  45.0,                                /* Expression: 45
                                        * Referenced by: '<Root>/Open Loop Duty Cycle'
                                        */
  30.0,                                /* Expression: 30
                                        * Referenced by: '<S1>/Constant3'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S1>/Constant1'
                                        */
  22.0,                                /* Expression: 22
                                        * Referenced by: '<S1>/Constant2'
                                        */
  146.0,                               /* Expression: 146
                                        * Referenced by: '<S1>/S2'
                                        */
  1.0,                                 /* Computed Parameter: Internal_D
                                        * Referenced by: '<S8>/Internal'
                                        */
  1.0                                  /* Computed Parameter: Internal_D_l
                                        * Referenced by: '<S12>/Internal'
                                        */
};

//Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
//--------------------------------------------------------------------------------
//Tool Version: Vivado v.2018.3 (lin64) Build 2405991 Thu Dec  6 23:36:41 MST 2018
//Date        : Sun Dec 19 12:50:52 2021
//Host        : laptop running 64-bit Ubuntu 16.04.7 LTS
//Command     : generate_target Base_Zynq_MPSoC_wrapper.bd
//Design      : Base_Zynq_MPSoC_wrapper
//Purpose     : IP block netlist
//--------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

module Base_Zynq_MPSoC_wrapper
   (led_4bits_tri_o);
  output [3:0]led_4bits_tri_o;

  wire [3:0]led_4bits_tri_o;

  Base_Zynq_MPSoC Base_Zynq_MPSoC_i
       (.led_4bits_tri_o(led_4bits_tri_o));
endmodule

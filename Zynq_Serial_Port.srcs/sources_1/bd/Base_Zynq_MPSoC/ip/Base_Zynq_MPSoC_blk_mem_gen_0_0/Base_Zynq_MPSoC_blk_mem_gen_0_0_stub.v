// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2018.3 (lin64) Build 2405991 Thu Dec  6 23:36:41 MST 2018
// Date        : Sun Aug 22 10:36:52 2021
// Host        : hp-laptop running 64-bit Ubuntu 20.04.2 LTS
// Command     : write_verilog -force -mode synth_stub
//               /home/hp/projects/moj-pardaz/xilinx/vivado/Zynq_Serial_Port/Zynq_Serial_Port.srcs/sources_1/bd/Base_Zynq_MPSoC/ip/Base_Zynq_MPSoC_blk_mem_gen_0_0/Base_Zynq_MPSoC_blk_mem_gen_0_0_stub.v
// Design      : Base_Zynq_MPSoC_blk_mem_gen_0_0
// Purpose     : Stub declaration of top-level module interface
// Device      : xczu7ev-ffvc1156-2-e
// --------------------------------------------------------------------------------

// This empty module with port declaration file causes synthesis tools to infer a black box for IP.
// The synthesis directives are for Synopsys Synplify support to prevent IO buffer insertion.
// Please paste the declaration into a Verilog source file or add the file as an additional source.
(* x_core_info = "blk_mem_gen_v8_4_2,Vivado 2018.3" *)
module Base_Zynq_MPSoC_blk_mem_gen_0_0(clka, rsta, ena, addra, douta, rsta_busy)
/* synthesis syn_black_box black_box_pad_pin="clka,rsta,ena,addra[31:0],douta[31:0],rsta_busy" */;
  input clka;
  input rsta;
  input ena;
  input [31:0]addra;
  output [31:0]douta;
  output rsta_busy;
endmodule

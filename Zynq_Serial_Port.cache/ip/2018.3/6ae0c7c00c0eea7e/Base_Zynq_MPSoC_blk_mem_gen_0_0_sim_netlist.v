// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2018.3 (lin64) Build 2405991 Thu Dec  6 23:36:41 MST 2018
// Date        : Thu Nov 19 10:04:33 2020
// Host        : hp running 64-bit Ubuntu 16.04.6 LTS
// Command     : write_verilog -force -mode funcsim -rename_top decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix -prefix
//               decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_ Base_Zynq_MPSoC_blk_mem_gen_0_0_sim_netlist.v
// Design      : Base_Zynq_MPSoC_blk_mem_gen_0_0
// Purpose     : This verilog netlist is a functional simulation representation of the design and should not be modified
//               or synthesized. This netlist cannot be used for SDF annotated simulation.
// Device      : xczu7ev-ffvc1156-2-e
// --------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

(* CHECK_LICENSE_TYPE = "Base_Zynq_MPSoC_blk_mem_gen_0_0,blk_mem_gen_v8_4_2,{}" *) (* downgradeipidentifiedwarnings = "yes" *) (* x_core_info = "blk_mem_gen_v8_4_2,Vivado 2018.3" *) 
(* NotValidForBitStream *)
module decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix
   (clka,
    rsta,
    ena,
    addra,
    douta,
    rsta_busy);
  (* x_interface_info = "xilinx.com:interface:bram:1.0 BRAM_PORTA CLK" *) (* x_interface_parameter = "XIL_INTERFACENAME BRAM_PORTA, MEM_SIZE 4096, MEM_WIDTH 32, MEM_ECC NONE, MASTER_TYPE BRAM_CTRL, READ_WRITE_MODE READ_ONLY, READ_LATENCY 1" *) input clka;
  (* x_interface_info = "xilinx.com:interface:bram:1.0 BRAM_PORTA RST" *) input rsta;
  (* x_interface_info = "xilinx.com:interface:bram:1.0 BRAM_PORTA EN" *) input ena;
  (* x_interface_info = "xilinx.com:interface:bram:1.0 BRAM_PORTA ADDR" *) input [31:0]addra;
  (* x_interface_info = "xilinx.com:interface:bram:1.0 BRAM_PORTA DOUT" *) output [31:0]douta;
  output rsta_busy;

  wire [31:0]addra;
  wire clka;
  wire [31:0]douta;
  wire ena;
  wire rsta;
  wire rsta_busy;
  wire NLW_U0_dbiterr_UNCONNECTED;
  wire NLW_U0_rstb_busy_UNCONNECTED;
  wire NLW_U0_s_axi_arready_UNCONNECTED;
  wire NLW_U0_s_axi_awready_UNCONNECTED;
  wire NLW_U0_s_axi_bvalid_UNCONNECTED;
  wire NLW_U0_s_axi_dbiterr_UNCONNECTED;
  wire NLW_U0_s_axi_rlast_UNCONNECTED;
  wire NLW_U0_s_axi_rvalid_UNCONNECTED;
  wire NLW_U0_s_axi_sbiterr_UNCONNECTED;
  wire NLW_U0_s_axi_wready_UNCONNECTED;
  wire NLW_U0_sbiterr_UNCONNECTED;
  wire [31:0]NLW_U0_doutb_UNCONNECTED;
  wire [31:0]NLW_U0_rdaddrecc_UNCONNECTED;
  wire [3:0]NLW_U0_s_axi_bid_UNCONNECTED;
  wire [1:0]NLW_U0_s_axi_bresp_UNCONNECTED;
  wire [31:0]NLW_U0_s_axi_rdaddrecc_UNCONNECTED;
  wire [31:0]NLW_U0_s_axi_rdata_UNCONNECTED;
  wire [3:0]NLW_U0_s_axi_rid_UNCONNECTED;
  wire [1:0]NLW_U0_s_axi_rresp_UNCONNECTED;

  (* C_ADDRA_WIDTH = "32" *) 
  (* C_ADDRB_WIDTH = "32" *) 
  (* C_ALGORITHM = "1" *) 
  (* C_AXI_ID_WIDTH = "4" *) 
  (* C_AXI_SLAVE_TYPE = "0" *) 
  (* C_AXI_TYPE = "1" *) 
  (* C_BYTE_SIZE = "8" *) 
  (* C_COMMON_CLK = "0" *) 
  (* C_COUNT_18K_BRAM = "0" *) 
  (* C_COUNT_36K_BRAM = "1" *) 
  (* C_CTRL_ECC_ALGO = "NONE" *) 
  (* C_DEFAULT_DATA = "0" *) 
  (* C_DISABLE_WARN_BHV_COLL = "0" *) 
  (* C_DISABLE_WARN_BHV_RANGE = "0" *) 
  (* C_ELABORATION_DIR = "./" *) 
  (* C_ENABLE_32BIT_ADDRESS = "1" *) 
  (* C_EN_DEEPSLEEP_PIN = "0" *) 
  (* C_EN_ECC_PIPE = "0" *) 
  (* C_EN_RDADDRA_CHG = "0" *) 
  (* C_EN_RDADDRB_CHG = "0" *) 
  (* C_EN_SAFETY_CKT = "1" *) 
  (* C_EN_SHUTDOWN_PIN = "0" *) 
  (* C_EN_SLEEP_PIN = "0" *) 
  (* C_EST_POWER_SUMMARY = "Estimated Power for IP     :     1.915875 mW" *) 
  (* C_FAMILY = "zynquplus" *) 
  (* C_HAS_AXI_ID = "0" *) 
  (* C_HAS_ENA = "1" *) 
  (* C_HAS_ENB = "0" *) 
  (* C_HAS_INJECTERR = "0" *) 
  (* C_HAS_MEM_OUTPUT_REGS_A = "0" *) 
  (* C_HAS_MEM_OUTPUT_REGS_B = "0" *) 
  (* C_HAS_MUX_OUTPUT_REGS_A = "0" *) 
  (* C_HAS_MUX_OUTPUT_REGS_B = "0" *) 
  (* C_HAS_REGCEA = "0" *) 
  (* C_HAS_REGCEB = "0" *) 
  (* C_HAS_RSTA = "1" *) 
  (* C_HAS_RSTB = "0" *) 
  (* C_HAS_SOFTECC_INPUT_REGS_A = "0" *) 
  (* C_HAS_SOFTECC_OUTPUT_REGS_B = "0" *) 
  (* C_INITA_VAL = "0" *) 
  (* C_INITB_VAL = "0" *) 
  (* C_INIT_FILE = "NONE" *) 
  (* C_INIT_FILE_NAME = "Base_Zynq_MPSoC_blk_mem_gen_0_0.mif" *) 
  (* C_INTERFACE_TYPE = "0" *) 
  (* C_LOAD_INIT_FILE = "1" *) 
  (* C_MEM_TYPE = "3" *) 
  (* C_MUX_PIPELINE_STAGES = "0" *) 
  (* C_PRIM_TYPE = "1" *) 
  (* C_READ_DEPTH_A = "1024" *) 
  (* C_READ_DEPTH_B = "1024" *) 
  (* C_READ_LATENCY_A = "1" *) 
  (* C_READ_LATENCY_B = "1" *) 
  (* C_READ_WIDTH_A = "32" *) 
  (* C_READ_WIDTH_B = "32" *) 
  (* C_RSTRAM_A = "0" *) 
  (* C_RSTRAM_B = "0" *) 
  (* C_RST_PRIORITY_A = "CE" *) 
  (* C_RST_PRIORITY_B = "CE" *) 
  (* C_SIM_COLLISION_CHECK = "ALL" *) 
  (* C_USE_BRAM_BLOCK = "1" *) 
  (* C_USE_BYTE_WEA = "0" *) 
  (* C_USE_BYTE_WEB = "0" *) 
  (* C_USE_DEFAULT_DATA = "0" *) 
  (* C_USE_ECC = "0" *) 
  (* C_USE_SOFTECC = "0" *) 
  (* C_USE_URAM = "0" *) 
  (* C_WEA_WIDTH = "1" *) 
  (* C_WEB_WIDTH = "1" *) 
  (* C_WRITE_DEPTH_A = "1024" *) 
  (* C_WRITE_DEPTH_B = "1024" *) 
  (* C_WRITE_MODE_A = "WRITE_FIRST" *) 
  (* C_WRITE_MODE_B = "WRITE_FIRST" *) 
  (* C_WRITE_WIDTH_A = "32" *) 
  (* C_WRITE_WIDTH_B = "32" *) 
  (* C_XDEVICEFAMILY = "zynquplus" *) 
  (* downgradeipidentifiedwarnings = "yes" *) 
  decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_blk_mem_gen_v8_4_2 U0
       (.addra(addra),
        .addrb({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0}),
        .clka(clka),
        .clkb(1'b0),
        .dbiterr(NLW_U0_dbiterr_UNCONNECTED),
        .deepsleep(1'b0),
        .dina({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0}),
        .dinb({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0}),
        .douta(douta),
        .doutb(NLW_U0_doutb_UNCONNECTED[31:0]),
        .eccpipece(1'b0),
        .ena(ena),
        .enb(1'b0),
        .injectdbiterr(1'b0),
        .injectsbiterr(1'b0),
        .rdaddrecc(NLW_U0_rdaddrecc_UNCONNECTED[31:0]),
        .regcea(1'b0),
        .regceb(1'b0),
        .rsta(rsta),
        .rsta_busy(rsta_busy),
        .rstb(1'b0),
        .rstb_busy(NLW_U0_rstb_busy_UNCONNECTED),
        .s_aclk(1'b0),
        .s_aresetn(1'b0),
        .s_axi_araddr({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0}),
        .s_axi_arburst({1'b0,1'b0}),
        .s_axi_arid({1'b0,1'b0,1'b0,1'b0}),
        .s_axi_arlen({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0}),
        .s_axi_arready(NLW_U0_s_axi_arready_UNCONNECTED),
        .s_axi_arsize({1'b0,1'b0,1'b0}),
        .s_axi_arvalid(1'b0),
        .s_axi_awaddr({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0}),
        .s_axi_awburst({1'b0,1'b0}),
        .s_axi_awid({1'b0,1'b0,1'b0,1'b0}),
        .s_axi_awlen({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0}),
        .s_axi_awready(NLW_U0_s_axi_awready_UNCONNECTED),
        .s_axi_awsize({1'b0,1'b0,1'b0}),
        .s_axi_awvalid(1'b0),
        .s_axi_bid(NLW_U0_s_axi_bid_UNCONNECTED[3:0]),
        .s_axi_bready(1'b0),
        .s_axi_bresp(NLW_U0_s_axi_bresp_UNCONNECTED[1:0]),
        .s_axi_bvalid(NLW_U0_s_axi_bvalid_UNCONNECTED),
        .s_axi_dbiterr(NLW_U0_s_axi_dbiterr_UNCONNECTED),
        .s_axi_injectdbiterr(1'b0),
        .s_axi_injectsbiterr(1'b0),
        .s_axi_rdaddrecc(NLW_U0_s_axi_rdaddrecc_UNCONNECTED[31:0]),
        .s_axi_rdata(NLW_U0_s_axi_rdata_UNCONNECTED[31:0]),
        .s_axi_rid(NLW_U0_s_axi_rid_UNCONNECTED[3:0]),
        .s_axi_rlast(NLW_U0_s_axi_rlast_UNCONNECTED),
        .s_axi_rready(1'b0),
        .s_axi_rresp(NLW_U0_s_axi_rresp_UNCONNECTED[1:0]),
        .s_axi_rvalid(NLW_U0_s_axi_rvalid_UNCONNECTED),
        .s_axi_sbiterr(NLW_U0_s_axi_sbiterr_UNCONNECTED),
        .s_axi_wdata({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0}),
        .s_axi_wlast(1'b0),
        .s_axi_wready(NLW_U0_s_axi_wready_UNCONNECTED),
        .s_axi_wstrb(1'b0),
        .s_axi_wvalid(1'b0),
        .sbiterr(NLW_U0_sbiterr_UNCONNECTED),
        .shutdown(1'b0),
        .sleep(1'b0),
        .wea(1'b0),
        .web(1'b0));
endmodule

module decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_blk_mem_gen_generic_cstr
   (douta,
    rsta_busy,
    clka,
    sleep,
    addra,
    rsta,
    ena);
  output [31:0]douta;
  output rsta_busy;
  input clka;
  input sleep;
  input [9:0]addra;
  input rsta;
  input ena;

  wire [9:0]addra;
  wire clka;
  wire [31:0]douta;
  wire ena;
  wire rsta;
  wire rsta_busy;
  wire sleep;

  decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_blk_mem_gen_prim_width \ramloop[0].ram.r 
       (.addra(addra),
        .clka(clka),
        .douta(douta),
        .ena(ena),
        .rsta(rsta),
        .rsta_busy(rsta_busy),
        .sleep(sleep));
endmodule

module decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_blk_mem_gen_prim_width
   (douta,
    rsta_busy,
    clka,
    sleep,
    addra,
    rsta,
    ena);
  output [31:0]douta;
  output rsta_busy;
  input clka;
  input sleep;
  input [9:0]addra;
  input rsta;
  input ena;

  wire ENA_dly;
  wire ENA_dly_D;
  wire POR_A;
  wire [4:0]RSTA_SHFT_REG;
  wire \SAFETY_CKT_GEN.RSTA_SHFT_REG_reg[3]_srl3_n_0 ;
  wire [9:0]addra;
  wire clka;
  wire [31:0]douta;
  wire ena;
  wire p_0_in;
  wire ram_rstram_a;
  wire ram_rstram_a_busy__0;
  wire rsta;
  wire rsta_busy;
  wire sleep;

  FDRE #(
    .INIT(1'b0)) 
    \SAFETY_CKT_GEN.ENA_NO_REG.ENA_dly_D_reg 
       (.C(clka),
        .CE(1'b1),
        .D(ENA_dly),
        .Q(ENA_dly_D),
        .R(1'b0));
  FDRE #(
    .INIT(1'b0)) 
    \SAFETY_CKT_GEN.ENA_NO_REG.ENA_dly_reg 
       (.C(clka),
        .CE(1'b1),
        .D(ram_rstram_a),
        .Q(ENA_dly),
        .R(1'b0));
  LUT2 #(
    .INIT(4'h6)) 
    \SAFETY_CKT_GEN.POR_A_i_1 
       (.I0(RSTA_SHFT_REG[0]),
        .I1(RSTA_SHFT_REG[4]),
        .O(p_0_in));
  FDRE #(
    .INIT(1'b0)) 
    \SAFETY_CKT_GEN.POR_A_reg 
       (.C(clka),
        .CE(1'b1),
        .D(p_0_in),
        .Q(POR_A),
        .R(1'b0));
  FDRE \SAFETY_CKT_GEN.RSTA_BUSY_NO_REG.RSTA_BUSY_reg 
       (.C(clka),
        .CE(1'b1),
        .D(ram_rstram_a_busy__0),
        .Q(rsta_busy),
        .R(1'b0));
  FDRE #(
    .INIT(1'b0)) 
    \SAFETY_CKT_GEN.RSTA_SHFT_REG_reg[0] 
       (.C(clka),
        .CE(1'b1),
        .D(1'b1),
        .Q(RSTA_SHFT_REG[0]),
        .R(1'b0));
  (* srl_bus_name = "U0/\inst_blk_mem_gen/gnbram.gnative_mem_map_bmg.native_mem_map_blk_mem_gen/valid.cstr/ramloop[0].ram.r/SAFETY_CKT_GEN.RSTA_SHFT_REG_reg " *) 
  (* srl_name = "U0/\inst_blk_mem_gen/gnbram.gnative_mem_map_bmg.native_mem_map_blk_mem_gen/valid.cstr/ramloop[0].ram.r/SAFETY_CKT_GEN.RSTA_SHFT_REG_reg[3]_srl3 " *) 
  SRL16E #(
    .INIT(16'h0000)) 
    \SAFETY_CKT_GEN.RSTA_SHFT_REG_reg[3]_srl3 
       (.A0(1'b0),
        .A1(1'b1),
        .A2(1'b0),
        .A3(1'b0),
        .CE(1'b1),
        .CLK(clka),
        .D(RSTA_SHFT_REG[0]),
        .Q(\SAFETY_CKT_GEN.RSTA_SHFT_REG_reg[3]_srl3_n_0 ));
  FDRE #(
    .INIT(1'b0)) 
    \SAFETY_CKT_GEN.RSTA_SHFT_REG_reg[4] 
       (.C(clka),
        .CE(1'b1),
        .D(\SAFETY_CKT_GEN.RSTA_SHFT_REG_reg[3]_srl3_n_0 ),
        .Q(RSTA_SHFT_REG[4]),
        .R(1'b0));
  decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_blk_mem_gen_prim_wrapper_init \prim_init.ram 
       (.ENA_dly_D(ENA_dly_D),
        .POR_A(POR_A),
        .addra(addra),
        .clka(clka),
        .douta(douta),
        .ena(ena),
        .ram_rstram_a(ram_rstram_a),
        .rsta(rsta),
        .sleep(sleep));
  LUT4 #(
    .INIT(16'hFFFE)) 
    ram_rstram_a_busy
       (.I0(POR_A),
        .I1(rsta),
        .I2(ENA_dly),
        .I3(ENA_dly_D),
        .O(ram_rstram_a_busy__0));
endmodule

module decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_blk_mem_gen_prim_wrapper_init
   (douta,
    ram_rstram_a,
    clka,
    sleep,
    addra,
    rsta,
    POR_A,
    ENA_dly_D,
    ena);
  output [31:0]douta;
  output ram_rstram_a;
  input clka;
  input sleep;
  input [9:0]addra;
  input rsta;
  input POR_A;
  input ENA_dly_D;
  input ena;

  wire \DEVICE_8SERIES.WITH_BMM_INFO.SP.SIMPLE_PRIM36.ram_n_140 ;
  wire \DEVICE_8SERIES.WITH_BMM_INFO.SP.SIMPLE_PRIM36.ram_n_141 ;
  wire \DEVICE_8SERIES.WITH_BMM_INFO.SP.SIMPLE_PRIM36.ram_n_142 ;
  wire \DEVICE_8SERIES.WITH_BMM_INFO.SP.SIMPLE_PRIM36.ram_n_143 ;
  wire ENA_I;
  wire ENA_dly_D;
  wire POR_A;
  wire [9:0]addra;
  wire clka;
  wire [31:0]douta;
  wire ena;
  wire ram_rstram_a;
  wire rsta;
  wire sleep;
  wire \NLW_DEVICE_8SERIES.WITH_BMM_INFO.SP.SIMPLE_PRIM36.ram_CASOUTDBITERR_UNCONNECTED ;
  wire \NLW_DEVICE_8SERIES.WITH_BMM_INFO.SP.SIMPLE_PRIM36.ram_CASOUTSBITERR_UNCONNECTED ;
  wire \NLW_DEVICE_8SERIES.WITH_BMM_INFO.SP.SIMPLE_PRIM36.ram_DBITERR_UNCONNECTED ;
  wire \NLW_DEVICE_8SERIES.WITH_BMM_INFO.SP.SIMPLE_PRIM36.ram_SBITERR_UNCONNECTED ;
  wire [31:0]\NLW_DEVICE_8SERIES.WITH_BMM_INFO.SP.SIMPLE_PRIM36.ram_CASDOUTA_UNCONNECTED ;
  wire [31:0]\NLW_DEVICE_8SERIES.WITH_BMM_INFO.SP.SIMPLE_PRIM36.ram_CASDOUTB_UNCONNECTED ;
  wire [3:0]\NLW_DEVICE_8SERIES.WITH_BMM_INFO.SP.SIMPLE_PRIM36.ram_CASDOUTPA_UNCONNECTED ;
  wire [3:0]\NLW_DEVICE_8SERIES.WITH_BMM_INFO.SP.SIMPLE_PRIM36.ram_CASDOUTPB_UNCONNECTED ;
  wire [31:0]\NLW_DEVICE_8SERIES.WITH_BMM_INFO.SP.SIMPLE_PRIM36.ram_DOUTBDOUT_UNCONNECTED ;
  wire [3:0]\NLW_DEVICE_8SERIES.WITH_BMM_INFO.SP.SIMPLE_PRIM36.ram_DOUTPBDOUTP_UNCONNECTED ;
  wire [7:0]\NLW_DEVICE_8SERIES.WITH_BMM_INFO.SP.SIMPLE_PRIM36.ram_ECCPARITY_UNCONNECTED ;
  wire [8:0]\NLW_DEVICE_8SERIES.WITH_BMM_INFO.SP.SIMPLE_PRIM36.ram_RDADDRECC_UNCONNECTED ;

  (* bmm_info_memory_device = "[31:0][0:1023]" *) 
  (* box_type = "PRIMITIVE" *) 
  RAMB36E2 #(
    .CASCADE_ORDER_A("NONE"),
    .CASCADE_ORDER_B("NONE"),
    .CLOCK_DOMAINS("COMMON"),
    .DOA_REG(0),
    .DOB_REG(0),
    .ENADDRENA("FALSE"),
    .ENADDRENB("FALSE"),
    .EN_ECC_PIPE("FALSE"),
    .EN_ECC_READ("FALSE"),
    .EN_ECC_WRITE("FALSE"),
    .INITP_00(256'h0000000000000000000000000000000000000000000000000000000000000000),
    .INITP_01(256'h0000000000000000000000000000000000000000000000000000000000000000),
    .INITP_02(256'h0000000000000000000000000000000000000000000000000000000000000000),
    .INITP_03(256'h0000000000000000000000000000000000000000000000000000000000000000),
    .INITP_04(256'h0000000000000000000000000000000000000000000000000000000000000000),
    .INITP_05(256'h0000000000000000000000000000000000000000000000000000000000000000),
    .INITP_06(256'h0000000000000000000000000000000000000000000000000000000000000000),
    .INITP_07(256'h0000000000000000000000000000000000000000000000000000000000000000),
    .INITP_08(256'h0000000000000000000000000000000000000000000000000000000000000000),
    .INITP_09(256'h0000000000000000000000000000000000000000000000000000000000000000),
    .INITP_0A(256'h0000000000000000000000000000000000000000000000000000000000000000),
    .INITP_0B(256'h0000000000000000000000000000000000000000000000000000000000000000),
    .INITP_0C(256'h0000000000000000000000000000000000000000000000000000000000000000),
    .INITP_0D(256'h0000000000000000000000000000000000000000000000000000000000000000),
    .INITP_0E(256'h0000000000000000000000000000000000000000000000000000000000000000),
    .INITP_0F(256'h0000000000000000000000000000000000000000000000000000000000000000),
    .INIT_00(256'h00007FFD00007FFD00007FFE00007FFE00007FFE00007FFE00007FFE00007FFF),
    .INIT_01(256'h00007FF600007FF700007FF800007FF900007FFA00007FFB00007FFB00007FFC),
    .INIT_02(256'h00007FEA00007FEC00007FED00007FEF00007FF100007FF200007FF300007FF5),
    .INIT_03(256'h00007FD900007FDC00007FDE00007FE000007FE200007FE400007FE600007FE8),
    .INIT_04(256'h00007FC400007FC700007FCA00007FCC00007FCF00007FD200007FD400007FD7),
    .INIT_05(256'h00007FA900007FAD00007FB000007FB400007FB700007FBA00007FBE00007FC1),
    .INIT_06(256'h00007F8A00007F8E00007F9200007F9600007F9A00007F9E00007FA200007FA6),
    .INIT_07(256'h00007F6500007F6A00007F6F00007F7400007F7800007F7D00007F8100007F85),
    .INIT_08(256'h00007F3C00007F4100007F4700007F4C00007F5100007F5600007F5B00007F60),
    .INIT_09(256'h00007F0E00007F1400007F1A00007F2000007F2500007F2B00007F3100007F36),
    .INIT_0A(256'h00007EDB00007EE100007EE800007EEE00007EF500007EFB00007F0100007F08),
    .INIT_0B(256'h00007EA300007EAA00007EB100007EB800007EBF00007EC600007ECD00007ED4),
    .INIT_0C(256'h00007E6600007E6D00007E7500007E7D00007E8500007E8C00007E9400007E9B),
    .INIT_0D(256'h00007E2400007E2C00007E3500007E3D00007E4500007E4D00007E5600007E5E),
    .INIT_0E(256'h00007DDD00007DE600007DEF00007DF800007E0100007E0A00007E1300007E1B),
    .INIT_0F(256'h00007D9100007D9B00007DA500007DAE00007DB800007DC100007DCB00007DD4),
    .INIT_10(256'h00007D4100007D4B00007D5600007D6000007D6A00007D7400007D7E00007D88),
    .INIT_11(256'h00007CEC00007CF700007D0200007D0C00007D1700007D2200007D2C00007D37),
    .INIT_12(256'h00007C9200007C9D00007CA900007CB400007CBF00007CCB00007CD600007CE1),
    .INIT_13(256'h00007C3300007C3F00007C4B00007C5700007C6300007C6F00007C7A00007C86),
    .INIT_14(256'h00007BCF00007BDC00007BE800007BF500007C0200007C0E00007C1A00007C27),
    .INIT_15(256'h00007B6700007B7400007B8100007B8E00007B9B00007BA800007BB500007BC2),
    .INIT_16(256'h00007AF900007B0700007B1500007B2300007B3100007B3E00007B4C00007B59),
    .INIT_17(256'h00007A8700007A9600007AA400007AB300007AC100007ACF00007ADD00007AEB),
    .INIT_18(256'h00007A1100007A2000007A2F00007A3E00007A4D00007A5B00007A6A00007A79),
    .INIT_19(256'h00007995000079A5000079B5000079C4000079D4000079E3000079F200007A02),
    .INIT_1A(256'h0000791500007925000079360000794600007956000079660000797600007985),
    .INIT_1B(256'h00007890000078A1000078B2000078C3000078D3000078E4000078F400007905),
    .INIT_1C(256'h00007807000078180000782A0000783B0000784C0000785D0000786E0000787F),
    .INIT_1D(256'h000077790000778B0000779D000077AF000077C0000077D2000077E4000077F5),
    .INIT_1E(256'h000076E6000076F90000770B0000771E00007730000077420000775400007767),
    .INIT_1F(256'h0000764F0000766200007675000076880000769B000076AE000076C1000076D3),
    .INIT_20(256'h000075B3000075C7000075DA000075EE0000760100007615000076280000763B),
    .INIT_21(256'h00007512000075270000753B0000754F00007563000075770000758B0000759F),
    .INIT_22(256'h0000746D0000748200007497000074AC000074C0000074D5000074EA000074FE),
    .INIT_23(256'h000073C4000073D9000073EF00007404000074190000742E0000744300007458),
    .INIT_24(256'h000073160000732C00007342000073580000736E0000738300007399000073AE),
    .INIT_25(256'h000072640000727A00007291000072A7000072BD000072D4000072EA00007300),
    .INIT_26(256'h000071AD000071C4000071DB000071F20000720900007220000072360000724D),
    .INIT_27(256'h000070F200007109000071210000713800007150000071670000717E00007196),
    .INIT_28(256'h000070320000704A000070620000707A00007092000070AA000070C2000070DA),
    .INIT_29(256'h00006F6E00006F8700006FA000006FB800006FD100006FE9000070020000701A),
    .INIT_2A(256'h00006EA600006EBF00006ED900006EF200006F0B00006F2400006F3D00006F55),
    .INIT_2B(256'h00006DDA00006DF300006E0D00006E2700006E4000006E5A00006E7300006E8D),
    .INIT_2C(256'h00006D0900006D2300006D3E00006D5800006D7200006D8C00006DA600006DC0),
    .INIT_2D(256'h00006C3400006C4F00006C6A00006C8400006C9F00006CBA00006CD400006CEF),
    .INIT_2E(256'h00006B5B00006B7600006B9200006BAD00006BC800006BE300006BFE00006C19),
    .INIT_2F(256'h00006A7E00006A9A00006AB500006AD100006AED00006B0800006B2400006B40),
    .INIT_30(256'h0000699C000069B9000069D5000069F100006A0E00006A2A00006A4600006A62),
    .INIT_31(256'h000068B7000068D4000068F10000690D0000692A000069470000696300006980),
    .INIT_32(256'h000067CD000067EB000068080000682500006843000068600000687D0000689A),
    .INIT_33(256'h000066E0000066FE0000671C0000673A000067570000677500006792000067B0),
    .INIT_34(256'h000065EF0000660D0000662B0000664A0000666800006686000066A4000066C2),
    .INIT_35(256'h000064F90000651800006537000065560000657400006593000065B2000065D0),
    .INIT_36(256'h000064000000641F0000643F0000645E0000647D0000649C000064BB000064DA),
    .INIT_37(256'h0000630300006323000063420000636200006382000063A1000063C1000063E0),
    .INIT_38(256'h0000620200006222000062420000626300006283000062A3000062C3000062E3),
    .INIT_39(256'h000060FD0000611E0000613E0000615F00006180000061A0000061C1000061E1),
    .INIT_3A(256'h00005FF4000060160000603700006058000060790000609A000060BB000060DC),
    .INIT_3B(256'h00005EE800005F0A00005F2C00005F4D00005F6F00005F9000005FB200005FD3),
    .INIT_3C(256'h00005DD800005DFA00005E1D00005E3F00005E6100005E8300005EA500005EC6),
    .INIT_3D(256'h00005CC500005CE700005D0A00005D2D00005D4F00005D7100005D9400005DB6),
    .INIT_3E(256'h00005BAE00005BD100005BF400005C1700005C3A00005C5D00005C7F00005CA2),
    .INIT_3F(256'h00005A9300005AB700005ADA00005AFD00005B2100005B4400005B6700005B8B),
    .INIT_40(256'h0000597500005999000059BD000059E100005A0400005A2800005A4C00005A6F),
    .INIT_41(256'h00005853000058780000589C000058C0000058E5000059090000592D00005951),
    .INIT_42(256'h0000572E00005753000057780000579D000057C1000057E60000580A0000582F),
    .INIT_43(256'h000056060000562B00005650000056750000569B000056C0000056E500005709),
    .INIT_44(256'h000054DA00005500000055250000554B0000557100005596000055BB000055E1),
    .INIT_45(256'h000053AB000053D1000053F70000541D00005443000054690000548F000054B5),
    .INIT_46(256'h00005279000052A0000052C6000052EC00005313000053390000535F00005385),
    .INIT_47(256'h000051440000516B00005191000051B8000051DF000052050000522C00005253),
    .INIT_48(256'h0000500B000050320000505A00005081000050A8000050CF000050F60000511D),
    .INIT_49(256'h00004ED000004EF700004F1F00004F4600004F6E00004F9500004FBD00004FE4),
    .INIT_4A(256'h00004D9100004DB900004DE100004E0900004E3100004E5800004E8000004EA8),
    .INIT_4B(256'h00004C4F00004C7800004CA000004CC800004CF000004D1900004D4100004D69),
    .INIT_4C(256'h00004B0B00004B3300004B5C00004B8500004BAD00004BD600004BFE00004C27),
    .INIT_4D(256'h000049C3000049EC00004A1500004A3E00004A6700004A9000004AB900004AE2),
    .INIT_4E(256'h00004879000048A2000048CC000048F50000491E00004948000049710000499A),
    .INIT_4F(256'h0000472C000047550000477F000047A9000047D2000047FC000048260000484F),
    .INIT_50(256'h000045DC00004606000046300000465A00004684000046AE000046D800004702),
    .INIT_51(256'h00004489000044B4000044DE00004508000045330000455D00004587000045B1),
    .INIT_52(256'h000043340000435F00004389000043B4000043DF00004409000044340000445F),
    .INIT_53(256'h000041DC00004207000042320000425D00004288000042B3000042DE00004309),
    .INIT_54(256'h00004082000040AD000040D8000041040000412F0000415A00004186000041B1),
    .INIT_55(256'h00003F2500003F5000003F7C00003FA800003FD300003FFF0000402B00004056),
    .INIT_56(256'h00003DC500003DF100003E1D00003E4900003E7500003EA100003ECD00003EF9),
    .INIT_57(256'h00003C6400003C9000003CBC00003CE900003D1500003D4100003D6D00003D99),
    .INIT_58(256'h00003B0000003B2C00003B5900003B8500003BB200003BDE00003C0B00003C37),
    .INIT_59(256'h00003999000039C6000039F300003A2000003A4D00003A7900003AA600003AD3),
    .INIT_5A(256'h000038310000385E0000388B000038B8000038E5000039120000393F0000396C),
    .INIT_5B(256'h000036C6000036F3000037210000374E0000377C000037A9000037D600003803),
    .INIT_5C(256'h0000355900003587000035B5000035E2000036100000363D0000366B00003698),
    .INIT_5D(256'h000033EA000034180000344600003474000034A2000034D0000034FE0000352B),
    .INIT_5E(256'h00003279000032A8000032D60000330400003332000033600000338E000033BC),
    .INIT_5F(256'h00003107000031350000316300003192000031C0000031EF0000321D0000324B),
    .INIT_60(256'h00002F9200002FC000002FEF0000301E0000304C0000307B000030A9000030D8),
    .INIT_61(256'h00002E1B00002E4A00002E7900002EA800002ED700002F0600002F3400002F63),
    .INIT_62(256'h00002CA300002CD200002D0100002D3000002D5F00002D8E00002DBD00002DEC),
    .INIT_63(256'h00002B2900002B5800002B8700002BB700002BE600002C1500002C4400002C74),
    .INIT_64(256'h000029AD000029DD00002A0C00002A3C00002A6B00002A9B00002ACA00002AF9),
    .INIT_65(256'h000028300000285F0000288F000028BF000028EE0000291E0000294E0000297D),
    .INIT_66(256'h000026B1000026E1000027110000274000002770000027A0000027D000002800),
    .INIT_67(256'h000025300000256000002591000025C1000025F1000026210000265100002681),
    .INIT_68(256'h000023AE000023DF0000240F0000243F00002470000024A0000024D000002500),
    .INIT_69(256'h0000222B0000225C0000228C000022BD000022ED0000231D0000234E0000237E),
    .INIT_6A(256'h000020A7000020D70000210800002139000021690000219A000021CA000021FB),
    .INIT_6B(256'h00001F2100001F5200001F8200001FB300001FE4000020150000204500002076),
    .INIT_6C(256'h00001D9A00001DCB00001DFC00001E2D00001E5D00001E8E00001EBF00001EF0),
    .INIT_6D(256'h00001C1200001C4300001C7400001CA500001CD600001D0700001D3800001D69),
    .INIT_6E(256'h00001A8800001ABA00001AEB00001B1C00001B4D00001B7E00001BAF00001BE1),
    .INIT_6F(256'h000018FE000019300000196100001992000019C3000019F500001A2600001A57),
    .INIT_70(256'h00001773000017A4000017D600001807000018390000186A0000189B000018CD),
    .INIT_71(256'h000015E7000016180000164A0000167B000016AD000016DF0000171000001741),
    .INIT_72(256'h0000145A0000148C000014BD000014EF000015200000155200001584000015B5),
    .INIT_73(256'h000012CC000012FE000013300000136100001393000013C5000013F600001428),
    .INIT_74(256'h0000113E0000116F000011A1000011D30000120500001237000012690000129A),
    .INIT_75(256'h00000FAE00000FE0000010120000104400001076000010A8000010DA0000110C),
    .INIT_76(256'h00000E1F00000E5100000E8300000EB500000EE700000F1900000F4B00000F7C),
    .INIT_77(256'h00000C8E00000CC000000CF200000D2500000D5700000D8900000DBB00000DED),
    .INIT_78(256'h00000AFE00000B3000000B6200000B9400000BC600000BF800000C2A00000C5C),
    .INIT_79(256'h0000096C0000099F000009D100000A0300000A3500000A6700000A9900000ACB),
    .INIT_7A(256'h000007DB0000080D0000083F00000871000008A4000008D6000009080000093A),
    .INIT_7B(256'h000006490000067B000006AD000006E0000007120000074400000776000007A9),
    .INIT_7C(256'h000004B7000004E90000051B0000054E00000580000005B2000005E400000617),
    .INIT_7D(256'h000003240000035700000389000003BB000003EE000004200000045200000484),
    .INIT_7E(256'h00000192000001C4000001F7000002290000025B0000028E000002C0000002F2),
    .INIT_7F(256'h00000000000000320000006400000096000000C9000000FB0000012D00000160),
    .INIT_A(36'h000000000),
    .INIT_B(36'h000000000),
    .INIT_FILE("NONE"),
    .IS_CLKARDCLK_INVERTED(1'b0),
    .IS_CLKBWRCLK_INVERTED(1'b0),
    .IS_ENARDEN_INVERTED(1'b0),
    .IS_ENBWREN_INVERTED(1'b0),
    .IS_RSTRAMARSTRAM_INVERTED(1'b0),
    .IS_RSTRAMB_INVERTED(1'b0),
    .IS_RSTREGARSTREG_INVERTED(1'b0),
    .IS_RSTREGB_INVERTED(1'b0),
    .RDADDRCHANGEA("FALSE"),
    .RDADDRCHANGEB("FALSE"),
    .READ_WIDTH_A(36),
    .READ_WIDTH_B(36),
    .RSTREG_PRIORITY_A("REGCE"),
    .RSTREG_PRIORITY_B("REGCE"),
    .SIM_COLLISION_CHECK("ALL"),
    .SLEEP_ASYNC("FALSE"),
    .SRVAL_A(36'h000000000),
    .SRVAL_B(36'h000000000),
    .WRITE_MODE_A("WRITE_FIRST"),
    .WRITE_MODE_B("WRITE_FIRST"),
    .WRITE_WIDTH_A(36),
    .WRITE_WIDTH_B(36)) 
    \DEVICE_8SERIES.WITH_BMM_INFO.SP.SIMPLE_PRIM36.ram 
       (.ADDRARDADDR({addra,1'b0,1'b0,1'b0,1'b0,1'b0}),
        .ADDRBWRADDR({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0}),
        .ADDRENA(1'b0),
        .ADDRENB(1'b0),
        .CASDIMUXA(1'b0),
        .CASDIMUXB(1'b0),
        .CASDINA({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0}),
        .CASDINB({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0}),
        .CASDINPA({1'b0,1'b0,1'b0,1'b0}),
        .CASDINPB({1'b0,1'b0,1'b0,1'b0}),
        .CASDOMUXA(1'b0),
        .CASDOMUXB(1'b0),
        .CASDOMUXEN_A(1'b0),
        .CASDOMUXEN_B(1'b0),
        .CASDOUTA(\NLW_DEVICE_8SERIES.WITH_BMM_INFO.SP.SIMPLE_PRIM36.ram_CASDOUTA_UNCONNECTED [31:0]),
        .CASDOUTB(\NLW_DEVICE_8SERIES.WITH_BMM_INFO.SP.SIMPLE_PRIM36.ram_CASDOUTB_UNCONNECTED [31:0]),
        .CASDOUTPA(\NLW_DEVICE_8SERIES.WITH_BMM_INFO.SP.SIMPLE_PRIM36.ram_CASDOUTPA_UNCONNECTED [3:0]),
        .CASDOUTPB(\NLW_DEVICE_8SERIES.WITH_BMM_INFO.SP.SIMPLE_PRIM36.ram_CASDOUTPB_UNCONNECTED [3:0]),
        .CASINDBITERR(1'b0),
        .CASINSBITERR(1'b0),
        .CASOREGIMUXA(1'b0),
        .CASOREGIMUXB(1'b0),
        .CASOREGIMUXEN_A(1'b0),
        .CASOREGIMUXEN_B(1'b0),
        .CASOUTDBITERR(\NLW_DEVICE_8SERIES.WITH_BMM_INFO.SP.SIMPLE_PRIM36.ram_CASOUTDBITERR_UNCONNECTED ),
        .CASOUTSBITERR(\NLW_DEVICE_8SERIES.WITH_BMM_INFO.SP.SIMPLE_PRIM36.ram_CASOUTSBITERR_UNCONNECTED ),
        .CLKARDCLK(clka),
        .CLKBWRCLK(clka),
        .DBITERR(\NLW_DEVICE_8SERIES.WITH_BMM_INFO.SP.SIMPLE_PRIM36.ram_DBITERR_UNCONNECTED ),
        .DINADIN({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0}),
        .DINBDIN({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0}),
        .DINPADINP({1'b0,1'b0,1'b0,1'b0}),
        .DINPBDINP({1'b0,1'b0,1'b0,1'b0}),
        .DOUTADOUT(douta),
        .DOUTBDOUT(\NLW_DEVICE_8SERIES.WITH_BMM_INFO.SP.SIMPLE_PRIM36.ram_DOUTBDOUT_UNCONNECTED [31:0]),
        .DOUTPADOUTP({\DEVICE_8SERIES.WITH_BMM_INFO.SP.SIMPLE_PRIM36.ram_n_140 ,\DEVICE_8SERIES.WITH_BMM_INFO.SP.SIMPLE_PRIM36.ram_n_141 ,\DEVICE_8SERIES.WITH_BMM_INFO.SP.SIMPLE_PRIM36.ram_n_142 ,\DEVICE_8SERIES.WITH_BMM_INFO.SP.SIMPLE_PRIM36.ram_n_143 }),
        .DOUTPBDOUTP(\NLW_DEVICE_8SERIES.WITH_BMM_INFO.SP.SIMPLE_PRIM36.ram_DOUTPBDOUTP_UNCONNECTED [3:0]),
        .ECCPARITY(\NLW_DEVICE_8SERIES.WITH_BMM_INFO.SP.SIMPLE_PRIM36.ram_ECCPARITY_UNCONNECTED [7:0]),
        .ECCPIPECE(1'b0),
        .ENARDEN(ENA_I),
        .ENBWREN(1'b0),
        .INJECTDBITERR(1'b0),
        .INJECTSBITERR(1'b0),
        .RDADDRECC(\NLW_DEVICE_8SERIES.WITH_BMM_INFO.SP.SIMPLE_PRIM36.ram_RDADDRECC_UNCONNECTED [8:0]),
        .REGCEAREGCE(1'b0),
        .REGCEB(1'b0),
        .RSTRAMARSTRAM(ram_rstram_a),
        .RSTRAMB(ram_rstram_a),
        .RSTREGARSTREG(1'b0),
        .RSTREGB(1'b0),
        .SBITERR(\NLW_DEVICE_8SERIES.WITH_BMM_INFO.SP.SIMPLE_PRIM36.ram_SBITERR_UNCONNECTED ),
        .SLEEP(sleep),
        .WEA({1'b0,1'b0,1'b0,1'b0}),
        .WEBWE({1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0,1'b0}));
  LUT2 #(
    .INIT(4'hE)) 
    \DEVICE_8SERIES.WITH_BMM_INFO.SP.SIMPLE_PRIM36.ram_i_1 
       (.I0(ENA_dly_D),
        .I1(ena),
        .O(ENA_I));
  LUT2 #(
    .INIT(4'hE)) 
    \DEVICE_8SERIES.WITH_BMM_INFO.SP.SIMPLE_PRIM36.ram_i_2 
       (.I0(rsta),
        .I1(POR_A),
        .O(ram_rstram_a));
endmodule

module decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_blk_mem_gen_top
   (douta,
    rsta_busy,
    clka,
    sleep,
    addra,
    rsta,
    ena);
  output [31:0]douta;
  output rsta_busy;
  input clka;
  input sleep;
  input [9:0]addra;
  input rsta;
  input ena;

  wire [9:0]addra;
  wire clka;
  wire [31:0]douta;
  wire ena;
  wire rsta;
  wire rsta_busy;
  wire sleep;

  decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_blk_mem_gen_generic_cstr \valid.cstr 
       (.addra(addra),
        .clka(clka),
        .douta(douta),
        .ena(ena),
        .rsta(rsta),
        .rsta_busy(rsta_busy),
        .sleep(sleep));
endmodule

(* C_ADDRA_WIDTH = "32" *) (* C_ADDRB_WIDTH = "32" *) (* C_ALGORITHM = "1" *) 
(* C_AXI_ID_WIDTH = "4" *) (* C_AXI_SLAVE_TYPE = "0" *) (* C_AXI_TYPE = "1" *) 
(* C_BYTE_SIZE = "8" *) (* C_COMMON_CLK = "0" *) (* C_COUNT_18K_BRAM = "0" *) 
(* C_COUNT_36K_BRAM = "1" *) (* C_CTRL_ECC_ALGO = "NONE" *) (* C_DEFAULT_DATA = "0" *) 
(* C_DISABLE_WARN_BHV_COLL = "0" *) (* C_DISABLE_WARN_BHV_RANGE = "0" *) (* C_ELABORATION_DIR = "./" *) 
(* C_ENABLE_32BIT_ADDRESS = "1" *) (* C_EN_DEEPSLEEP_PIN = "0" *) (* C_EN_ECC_PIPE = "0" *) 
(* C_EN_RDADDRA_CHG = "0" *) (* C_EN_RDADDRB_CHG = "0" *) (* C_EN_SAFETY_CKT = "1" *) 
(* C_EN_SHUTDOWN_PIN = "0" *) (* C_EN_SLEEP_PIN = "0" *) (* C_EST_POWER_SUMMARY = "Estimated Power for IP     :     1.915875 mW" *) 
(* C_FAMILY = "zynquplus" *) (* C_HAS_AXI_ID = "0" *) (* C_HAS_ENA = "1" *) 
(* C_HAS_ENB = "0" *) (* C_HAS_INJECTERR = "0" *) (* C_HAS_MEM_OUTPUT_REGS_A = "0" *) 
(* C_HAS_MEM_OUTPUT_REGS_B = "0" *) (* C_HAS_MUX_OUTPUT_REGS_A = "0" *) (* C_HAS_MUX_OUTPUT_REGS_B = "0" *) 
(* C_HAS_REGCEA = "0" *) (* C_HAS_REGCEB = "0" *) (* C_HAS_RSTA = "1" *) 
(* C_HAS_RSTB = "0" *) (* C_HAS_SOFTECC_INPUT_REGS_A = "0" *) (* C_HAS_SOFTECC_OUTPUT_REGS_B = "0" *) 
(* C_INITA_VAL = "0" *) (* C_INITB_VAL = "0" *) (* C_INIT_FILE = "NONE" *) 
(* C_INIT_FILE_NAME = "Base_Zynq_MPSoC_blk_mem_gen_0_0.mif" *) (* C_INTERFACE_TYPE = "0" *) (* C_LOAD_INIT_FILE = "1" *) 
(* C_MEM_TYPE = "3" *) (* C_MUX_PIPELINE_STAGES = "0" *) (* C_PRIM_TYPE = "1" *) 
(* C_READ_DEPTH_A = "1024" *) (* C_READ_DEPTH_B = "1024" *) (* C_READ_LATENCY_A = "1" *) 
(* C_READ_LATENCY_B = "1" *) (* C_READ_WIDTH_A = "32" *) (* C_READ_WIDTH_B = "32" *) 
(* C_RSTRAM_A = "0" *) (* C_RSTRAM_B = "0" *) (* C_RST_PRIORITY_A = "CE" *) 
(* C_RST_PRIORITY_B = "CE" *) (* C_SIM_COLLISION_CHECK = "ALL" *) (* C_USE_BRAM_BLOCK = "1" *) 
(* C_USE_BYTE_WEA = "0" *) (* C_USE_BYTE_WEB = "0" *) (* C_USE_DEFAULT_DATA = "0" *) 
(* C_USE_ECC = "0" *) (* C_USE_SOFTECC = "0" *) (* C_USE_URAM = "0" *) 
(* C_WEA_WIDTH = "1" *) (* C_WEB_WIDTH = "1" *) (* C_WRITE_DEPTH_A = "1024" *) 
(* C_WRITE_DEPTH_B = "1024" *) (* C_WRITE_MODE_A = "WRITE_FIRST" *) (* C_WRITE_MODE_B = "WRITE_FIRST" *) 
(* C_WRITE_WIDTH_A = "32" *) (* C_WRITE_WIDTH_B = "32" *) (* C_XDEVICEFAMILY = "zynquplus" *) 
(* downgradeipidentifiedwarnings = "yes" *) 
module decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_blk_mem_gen_v8_4_2
   (clka,
    rsta,
    ena,
    regcea,
    wea,
    addra,
    dina,
    douta,
    clkb,
    rstb,
    enb,
    regceb,
    web,
    addrb,
    dinb,
    doutb,
    injectsbiterr,
    injectdbiterr,
    eccpipece,
    sbiterr,
    dbiterr,
    rdaddrecc,
    sleep,
    deepsleep,
    shutdown,
    rsta_busy,
    rstb_busy,
    s_aclk,
    s_aresetn,
    s_axi_awid,
    s_axi_awaddr,
    s_axi_awlen,
    s_axi_awsize,
    s_axi_awburst,
    s_axi_awvalid,
    s_axi_awready,
    s_axi_wdata,
    s_axi_wstrb,
    s_axi_wlast,
    s_axi_wvalid,
    s_axi_wready,
    s_axi_bid,
    s_axi_bresp,
    s_axi_bvalid,
    s_axi_bready,
    s_axi_arid,
    s_axi_araddr,
    s_axi_arlen,
    s_axi_arsize,
    s_axi_arburst,
    s_axi_arvalid,
    s_axi_arready,
    s_axi_rid,
    s_axi_rdata,
    s_axi_rresp,
    s_axi_rlast,
    s_axi_rvalid,
    s_axi_rready,
    s_axi_injectsbiterr,
    s_axi_injectdbiterr,
    s_axi_sbiterr,
    s_axi_dbiterr,
    s_axi_rdaddrecc);
  input clka;
  input rsta;
  input ena;
  input regcea;
  input [0:0]wea;
  input [31:0]addra;
  input [31:0]dina;
  output [31:0]douta;
  input clkb;
  input rstb;
  input enb;
  input regceb;
  input [0:0]web;
  input [31:0]addrb;
  input [31:0]dinb;
  output [31:0]doutb;
  input injectsbiterr;
  input injectdbiterr;
  input eccpipece;
  output sbiterr;
  output dbiterr;
  output [31:0]rdaddrecc;
  input sleep;
  input deepsleep;
  input shutdown;
  output rsta_busy;
  output rstb_busy;
  input s_aclk;
  input s_aresetn;
  input [3:0]s_axi_awid;
  input [31:0]s_axi_awaddr;
  input [7:0]s_axi_awlen;
  input [2:0]s_axi_awsize;
  input [1:0]s_axi_awburst;
  input s_axi_awvalid;
  output s_axi_awready;
  input [31:0]s_axi_wdata;
  input [0:0]s_axi_wstrb;
  input s_axi_wlast;
  input s_axi_wvalid;
  output s_axi_wready;
  output [3:0]s_axi_bid;
  output [1:0]s_axi_bresp;
  output s_axi_bvalid;
  input s_axi_bready;
  input [3:0]s_axi_arid;
  input [31:0]s_axi_araddr;
  input [7:0]s_axi_arlen;
  input [2:0]s_axi_arsize;
  input [1:0]s_axi_arburst;
  input s_axi_arvalid;
  output s_axi_arready;
  output [3:0]s_axi_rid;
  output [31:0]s_axi_rdata;
  output [1:0]s_axi_rresp;
  output s_axi_rlast;
  output s_axi_rvalid;
  input s_axi_rready;
  input s_axi_injectsbiterr;
  input s_axi_injectdbiterr;
  output s_axi_sbiterr;
  output s_axi_dbiterr;
  output [31:0]s_axi_rdaddrecc;

  wire \<const0> ;
  wire [31:0]addra;
  wire clka;
  wire [31:0]douta;
  wire ena;
  wire rsta;
  wire rsta_busy;
  wire sleep;

  assign dbiterr = \<const0> ;
  assign doutb[31] = \<const0> ;
  assign doutb[30] = \<const0> ;
  assign doutb[29] = \<const0> ;
  assign doutb[28] = \<const0> ;
  assign doutb[27] = \<const0> ;
  assign doutb[26] = \<const0> ;
  assign doutb[25] = \<const0> ;
  assign doutb[24] = \<const0> ;
  assign doutb[23] = \<const0> ;
  assign doutb[22] = \<const0> ;
  assign doutb[21] = \<const0> ;
  assign doutb[20] = \<const0> ;
  assign doutb[19] = \<const0> ;
  assign doutb[18] = \<const0> ;
  assign doutb[17] = \<const0> ;
  assign doutb[16] = \<const0> ;
  assign doutb[15] = \<const0> ;
  assign doutb[14] = \<const0> ;
  assign doutb[13] = \<const0> ;
  assign doutb[12] = \<const0> ;
  assign doutb[11] = \<const0> ;
  assign doutb[10] = \<const0> ;
  assign doutb[9] = \<const0> ;
  assign doutb[8] = \<const0> ;
  assign doutb[7] = \<const0> ;
  assign doutb[6] = \<const0> ;
  assign doutb[5] = \<const0> ;
  assign doutb[4] = \<const0> ;
  assign doutb[3] = \<const0> ;
  assign doutb[2] = \<const0> ;
  assign doutb[1] = \<const0> ;
  assign doutb[0] = \<const0> ;
  assign rdaddrecc[31] = \<const0> ;
  assign rdaddrecc[30] = \<const0> ;
  assign rdaddrecc[29] = \<const0> ;
  assign rdaddrecc[28] = \<const0> ;
  assign rdaddrecc[27] = \<const0> ;
  assign rdaddrecc[26] = \<const0> ;
  assign rdaddrecc[25] = \<const0> ;
  assign rdaddrecc[24] = \<const0> ;
  assign rdaddrecc[23] = \<const0> ;
  assign rdaddrecc[22] = \<const0> ;
  assign rdaddrecc[21] = \<const0> ;
  assign rdaddrecc[20] = \<const0> ;
  assign rdaddrecc[19] = \<const0> ;
  assign rdaddrecc[18] = \<const0> ;
  assign rdaddrecc[17] = \<const0> ;
  assign rdaddrecc[16] = \<const0> ;
  assign rdaddrecc[15] = \<const0> ;
  assign rdaddrecc[14] = \<const0> ;
  assign rdaddrecc[13] = \<const0> ;
  assign rdaddrecc[12] = \<const0> ;
  assign rdaddrecc[11] = \<const0> ;
  assign rdaddrecc[10] = \<const0> ;
  assign rdaddrecc[9] = \<const0> ;
  assign rdaddrecc[8] = \<const0> ;
  assign rdaddrecc[7] = \<const0> ;
  assign rdaddrecc[6] = \<const0> ;
  assign rdaddrecc[5] = \<const0> ;
  assign rdaddrecc[4] = \<const0> ;
  assign rdaddrecc[3] = \<const0> ;
  assign rdaddrecc[2] = \<const0> ;
  assign rdaddrecc[1] = \<const0> ;
  assign rdaddrecc[0] = \<const0> ;
  assign rstb_busy = \<const0> ;
  assign s_axi_arready = \<const0> ;
  assign s_axi_awready = \<const0> ;
  assign s_axi_bid[3] = \<const0> ;
  assign s_axi_bid[2] = \<const0> ;
  assign s_axi_bid[1] = \<const0> ;
  assign s_axi_bid[0] = \<const0> ;
  assign s_axi_bresp[1] = \<const0> ;
  assign s_axi_bresp[0] = \<const0> ;
  assign s_axi_bvalid = \<const0> ;
  assign s_axi_dbiterr = \<const0> ;
  assign s_axi_rdaddrecc[31] = \<const0> ;
  assign s_axi_rdaddrecc[30] = \<const0> ;
  assign s_axi_rdaddrecc[29] = \<const0> ;
  assign s_axi_rdaddrecc[28] = \<const0> ;
  assign s_axi_rdaddrecc[27] = \<const0> ;
  assign s_axi_rdaddrecc[26] = \<const0> ;
  assign s_axi_rdaddrecc[25] = \<const0> ;
  assign s_axi_rdaddrecc[24] = \<const0> ;
  assign s_axi_rdaddrecc[23] = \<const0> ;
  assign s_axi_rdaddrecc[22] = \<const0> ;
  assign s_axi_rdaddrecc[21] = \<const0> ;
  assign s_axi_rdaddrecc[20] = \<const0> ;
  assign s_axi_rdaddrecc[19] = \<const0> ;
  assign s_axi_rdaddrecc[18] = \<const0> ;
  assign s_axi_rdaddrecc[17] = \<const0> ;
  assign s_axi_rdaddrecc[16] = \<const0> ;
  assign s_axi_rdaddrecc[15] = \<const0> ;
  assign s_axi_rdaddrecc[14] = \<const0> ;
  assign s_axi_rdaddrecc[13] = \<const0> ;
  assign s_axi_rdaddrecc[12] = \<const0> ;
  assign s_axi_rdaddrecc[11] = \<const0> ;
  assign s_axi_rdaddrecc[10] = \<const0> ;
  assign s_axi_rdaddrecc[9] = \<const0> ;
  assign s_axi_rdaddrecc[8] = \<const0> ;
  assign s_axi_rdaddrecc[7] = \<const0> ;
  assign s_axi_rdaddrecc[6] = \<const0> ;
  assign s_axi_rdaddrecc[5] = \<const0> ;
  assign s_axi_rdaddrecc[4] = \<const0> ;
  assign s_axi_rdaddrecc[3] = \<const0> ;
  assign s_axi_rdaddrecc[2] = \<const0> ;
  assign s_axi_rdaddrecc[1] = \<const0> ;
  assign s_axi_rdaddrecc[0] = \<const0> ;
  assign s_axi_rdata[31] = \<const0> ;
  assign s_axi_rdata[30] = \<const0> ;
  assign s_axi_rdata[29] = \<const0> ;
  assign s_axi_rdata[28] = \<const0> ;
  assign s_axi_rdata[27] = \<const0> ;
  assign s_axi_rdata[26] = \<const0> ;
  assign s_axi_rdata[25] = \<const0> ;
  assign s_axi_rdata[24] = \<const0> ;
  assign s_axi_rdata[23] = \<const0> ;
  assign s_axi_rdata[22] = \<const0> ;
  assign s_axi_rdata[21] = \<const0> ;
  assign s_axi_rdata[20] = \<const0> ;
  assign s_axi_rdata[19] = \<const0> ;
  assign s_axi_rdata[18] = \<const0> ;
  assign s_axi_rdata[17] = \<const0> ;
  assign s_axi_rdata[16] = \<const0> ;
  assign s_axi_rdata[15] = \<const0> ;
  assign s_axi_rdata[14] = \<const0> ;
  assign s_axi_rdata[13] = \<const0> ;
  assign s_axi_rdata[12] = \<const0> ;
  assign s_axi_rdata[11] = \<const0> ;
  assign s_axi_rdata[10] = \<const0> ;
  assign s_axi_rdata[9] = \<const0> ;
  assign s_axi_rdata[8] = \<const0> ;
  assign s_axi_rdata[7] = \<const0> ;
  assign s_axi_rdata[6] = \<const0> ;
  assign s_axi_rdata[5] = \<const0> ;
  assign s_axi_rdata[4] = \<const0> ;
  assign s_axi_rdata[3] = \<const0> ;
  assign s_axi_rdata[2] = \<const0> ;
  assign s_axi_rdata[1] = \<const0> ;
  assign s_axi_rdata[0] = \<const0> ;
  assign s_axi_rid[3] = \<const0> ;
  assign s_axi_rid[2] = \<const0> ;
  assign s_axi_rid[1] = \<const0> ;
  assign s_axi_rid[0] = \<const0> ;
  assign s_axi_rlast = \<const0> ;
  assign s_axi_rresp[1] = \<const0> ;
  assign s_axi_rresp[0] = \<const0> ;
  assign s_axi_rvalid = \<const0> ;
  assign s_axi_sbiterr = \<const0> ;
  assign s_axi_wready = \<const0> ;
  assign sbiterr = \<const0> ;
  GND GND
       (.G(\<const0> ));
  decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_blk_mem_gen_v8_4_2_synth inst_blk_mem_gen
       (.addra(addra[11:2]),
        .clka(clka),
        .douta(douta),
        .ena(ena),
        .rsta(rsta),
        .rsta_busy(rsta_busy),
        .sleep(sleep));
endmodule

module decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_blk_mem_gen_v8_4_2_synth
   (douta,
    rsta_busy,
    clka,
    sleep,
    addra,
    rsta,
    ena);
  output [31:0]douta;
  output rsta_busy;
  input clka;
  input sleep;
  input [9:0]addra;
  input rsta;
  input ena;

  wire [9:0]addra;
  wire clka;
  wire [31:0]douta;
  wire ena;
  wire rsta;
  wire rsta_busy;
  wire sleep;

  decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_blk_mem_gen_top \gnbram.gnative_mem_map_bmg.native_mem_map_blk_mem_gen 
       (.addra(addra),
        .clka(clka),
        .douta(douta),
        .ena(ena),
        .rsta(rsta),
        .rsta_busy(rsta_busy),
        .sleep(sleep));
endmodule
`ifndef GLBL
`define GLBL
`timescale  1 ps / 1 ps

module glbl ();

    parameter ROC_WIDTH = 100000;
    parameter TOC_WIDTH = 0;

//--------   STARTUP Globals --------------
    wire GSR;
    wire GTS;
    wire GWE;
    wire PRLD;
    tri1 p_up_tmp;
    tri (weak1, strong0) PLL_LOCKG = p_up_tmp;

    wire PROGB_GLBL;
    wire CCLKO_GLBL;
    wire FCSBO_GLBL;
    wire [3:0] DO_GLBL;
    wire [3:0] DI_GLBL;
   
    reg GSR_int;
    reg GTS_int;
    reg PRLD_int;

//--------   JTAG Globals --------------
    wire JTAG_TDO_GLBL;
    wire JTAG_TCK_GLBL;
    wire JTAG_TDI_GLBL;
    wire JTAG_TMS_GLBL;
    wire JTAG_TRST_GLBL;

    reg JTAG_CAPTURE_GLBL;
    reg JTAG_RESET_GLBL;
    reg JTAG_SHIFT_GLBL;
    reg JTAG_UPDATE_GLBL;
    reg JTAG_RUNTEST_GLBL;

    reg JTAG_SEL1_GLBL = 0;
    reg JTAG_SEL2_GLBL = 0 ;
    reg JTAG_SEL3_GLBL = 0;
    reg JTAG_SEL4_GLBL = 0;

    reg JTAG_USER_TDO1_GLBL = 1'bz;
    reg JTAG_USER_TDO2_GLBL = 1'bz;
    reg JTAG_USER_TDO3_GLBL = 1'bz;
    reg JTAG_USER_TDO4_GLBL = 1'bz;

    assign (strong1, weak0) GSR = GSR_int;
    assign (strong1, weak0) GTS = GTS_int;
    assign (weak1, weak0) PRLD = PRLD_int;

    initial begin
	GSR_int = 1'b1;
	PRLD_int = 1'b1;
	#(ROC_WIDTH)
	GSR_int = 1'b0;
	PRLD_int = 1'b0;
    end

    initial begin
	GTS_int = 1'b1;
	#(TOC_WIDTH)
	GTS_int = 1'b0;
    end

endmodule
`endif

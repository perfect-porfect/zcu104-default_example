
Q
Command: %s
53*	vivadotcl2 
place_design2default:defaultZ4-113h px? 
?
@Attempting to get a license for feature '%s' and/or device '%s'
308*common2"
Implementation2default:default2
xczu7ev2default:defaultZ17-347h px? 
?
0Got license for feature '%s' and/or device '%s'
310*common2"
Implementation2default:default2
xczu7ev2default:defaultZ17-349h px? 
P
Running DRC with %s threads
24*drc2
82default:defaultZ23-27h px? 
V
DRC finished with %s
79*	vivadotcl2
0 Errors2default:defaultZ4-198h px? 
e
BPlease refer to the DRC report (report_drc) for more information.
80*	vivadotclZ4-199h px? 
p
,Running DRC as a precondition to command %s
22*	vivadotcl2 
place_design2default:defaultZ4-22h px? 
P
Running DRC with %s threads
24*drc2
82default:defaultZ23-27h px? 
V
DRC finished with %s
79*	vivadotcl2
0 Errors2default:defaultZ4-198h px? 
e
BPlease refer to the DRC report (report_drc) for more information.
80*	vivadotclZ4-199h px? 
U

Starting %s Task
103*constraints2
Placer2default:defaultZ18-103h px? 
}
BMultithreading enabled for place_design using a maximum of %s CPUs12*	placeflow2
82default:defaultZ30-611h px? 
v

Phase %s%s
101*constraints2
1 2default:default2)
Placer Initialization2default:defaultZ18-101h px? 
?

Phase %s%s
101*constraints2
1.1 2default:default29
%Placer Initialization Netlist Sorting2default:defaultZ18-101h px? 
?
r%sTime (s): cpu = %s ; elapsed = %s . Memory (MB): peak = %s ; gain = %s ; free physical = %s ; free virtual = %s
480*common2.
Netlist sorting complete. 2default:default2
00:00:00.012default:default2
00:00:002default:default2
4446.9772default:default2
0.0002default:default2
17312default:default2
126292default:defaultZ17-722h px? 
[
FPhase 1.1 Placer Initialization Netlist Sorting | Checksum: 17636fbf1
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:00:00.02 ; elapsed = 00:00:00.04 . Memory (MB): peak = 4446.977 ; gain = 0.000 ; free physical = 1731 ; free virtual = 126292default:defaulth px? 
?
r%sTime (s): cpu = %s ; elapsed = %s . Memory (MB): peak = %s ; gain = %s ; free physical = %s ; free virtual = %s
480*common2.
Netlist sorting complete. 2default:default2
00:00:00.012default:default2
00:00:002default:default2
4446.9772default:default2
0.0002default:default2
17312default:default2
126302default:defaultZ17-722h px? 
?

Phase %s%s
101*constraints2
1.2 2default:default2F
2IO Placement/ Clock Placement/ Build Placer Device2default:defaultZ18-101h px? 
E
%Done setting XDC timing constraints.
35*timingZ38-35h px? 
h
SPhase 1.2 IO Placement/ Clock Placement/ Build Placer Device | Checksum: 10964c623
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:00:14 ; elapsed = 00:00:05 . Memory (MB): peak = 4446.977 ; gain = 0.000 ; free physical = 1712 ; free virtual = 126152default:defaulth px? 
}

Phase %s%s
101*constraints2
1.3 2default:default2.
Build Placer Netlist Model2default:defaultZ18-101h px? 
P
;Phase 1.3 Build Placer Netlist Model | Checksum: 14bbb2f8f
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:00:24 ; elapsed = 00:00:08 . Memory (MB): peak = 4446.977 ; gain = 0.000 ; free physical = 1699 ; free virtual = 126032default:defaulth px? 
z

Phase %s%s
101*constraints2
1.4 2default:default2+
Constrain Clocks/Macros2default:defaultZ18-101h px? 
M
8Phase 1.4 Constrain Clocks/Macros | Checksum: 14bbb2f8f
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:00:24 ; elapsed = 00:00:08 . Memory (MB): peak = 4446.977 ; gain = 0.000 ; free physical = 1699 ; free virtual = 126032default:defaulth px? 
I
4Phase 1 Placer Initialization | Checksum: 14bbb2f8f
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:00:24 ; elapsed = 00:00:08 . Memory (MB): peak = 4446.977 ; gain = 0.000 ; free physical = 1699 ; free virtual = 126032default:defaulth px? 
q

Phase %s%s
101*constraints2
2 2default:default2$
Global Placement2default:defaultZ18-101h px? 
p

Phase %s%s
101*constraints2
2.1 2default:default2!
Floorplanning2default:defaultZ18-101h px? 
C
.Phase 2.1 Floorplanning | Checksum: 17ca4ddc4
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:00:43 ; elapsed = 00:00:17 . Memory (MB): peak = 4446.977 ; gain = 0.000 ; free physical = 1624 ; free virtual = 125302default:defaulth px? 


Phase %s%s
101*constraints2
2.2 2default:default20
Physical Synthesis In Placer2default:defaultZ18-101h px? 
?
=Pass %s. Identified %s candidate %s for fanout optimization.
76*physynth2
12default:default2
12default:default2
net2default:defaultZ32-76h px? 
?
'Processed net %s. Replicated %s times.
81*physynth2?
9Base_Zynq_MPSoC_i/rst_ps8_0_100M/U0/peripheral_aresetn[0]9Base_Zynq_MPSoC_i/rst_ps8_0_100M/U0/peripheral_aresetn[0]2default:default2
62default:default8Z32-81h px? 
?
$Optimized %s %s. Created %s new %s.
216*physynth2
12default:default2
net2default:default2
62default:default2
	instances2default:defaultZ32-232h px? 
?
aEnd %s Pass. Optimized %s %s. Created %s new %s, deleted %s existing %s and moved %s existing %s
415*physynth2
12default:default2
12default:default2
net or cell2default:default2
62default:default2
cells2default:default2
02default:default2
cell2default:default2
02default:default2
cell2default:defaultZ32-775h px? 
?
r%sTime (s): cpu = %s ; elapsed = %s . Memory (MB): peak = %s ; gain = %s ; free physical = %s ; free virtual = %s
480*common2.
Netlist sorting complete. 2default:default2
00:00:00.092default:default2
00:00:00.092default:default2
4446.9772default:default2
0.0002default:default2
16152default:default2
125232default:defaultZ17-722h px? 
j
FNo candidate cells for DSP register optimization found in the design.
274*physynthZ32-456h px? 
?
aEnd %s Pass. Optimized %s %s. Created %s new %s, deleted %s existing %s and moved %s existing %s
415*physynth2
22default:default2
02default:default2
net or cell2default:default2
02default:default2
cell2default:default2
02default:default2
cell2default:default2
02default:default2
cell2default:defaultZ32-775h px? 
h
DNo candidate cells for SRL register optimization found in the design349*physynthZ32-677h px? 
?
aEnd %s Pass. Optimized %s %s. Created %s new %s, deleted %s existing %s and moved %s existing %s
415*physynth2
12default:default2
02default:default2
net or cell2default:default2
02default:default2
cell2default:default2
02default:default2
cell2default:default2
02default:default2
cell2default:defaultZ32-775h px? 
i
ENo candidate cells for BRAM register optimization found in the design297*physynthZ32-526h px? 
?
aEnd %s Pass. Optimized %s %s. Created %s new %s, deleted %s existing %s and moved %s existing %s
415*physynth2
12default:default2
02default:default2
net or cell2default:default2
02default:default2
cell2default:default2
02default:default2
cell2default:default2
02default:default2
cell2default:defaultZ32-775h px? 
R
.No candidate nets found for HD net replication521*physynthZ32-949h px? 
?
aEnd %s Pass. Optimized %s %s. Created %s new %s, deleted %s existing %s and moved %s existing %s
415*physynth2
12default:default2
02default:default2
net or cell2default:default2
02default:default2
cell2default:default2
02default:default2
cell2default:default2
02default:default2
cell2default:defaultZ32-775h px? 
?
r%sTime (s): cpu = %s ; elapsed = %s . Memory (MB): peak = %s ; gain = %s ; free physical = %s ; free virtual = %s
480*common2.
Netlist sorting complete. 2default:default2
00:00:00.012default:default2
00:00:00.012default:default2
4446.9772default:default2
0.0002default:default2
16162default:default2
125232default:defaultZ17-722h px? 
B
-
Summary of Physical Synthesis Optimizations
*commonh px? 
B
-============================================
*commonh px? 


*commonh px? 


*commonh px? 
?
?----------------------------------------------------------------------------------------------------------------------------------------
*commonh px? 
?
?|  Optimization                  |  Added Cells  |  Removed Cells  |  Optimized Cells/Nets  |  Dont Touch  |  Iterations  |  Elapsed   |
----------------------------------------------------------------------------------------------------------------------------------------
*commonh px? 
?
?|  Very High Fanout              |            6  |              0  |                     1  |           0  |           1  |  00:00:01  |
|  DSP Register                  |            0  |              0  |                     0  |           0  |           1  |  00:00:00  |
|  Shift Register                |            0  |              0  |                     0  |           0  |           1  |  00:00:00  |
|  BRAM Register                 |            0  |              0  |                     0  |           0  |           1  |  00:00:00  |
|  HD Interface Net Replication  |            0  |              0  |                     0  |           0  |           1  |  00:00:00  |
|  Total                         |            6  |              0  |                     1  |           0  |           5  |  00:00:01  |
----------------------------------------------------------------------------------------------------------------------------------------
*commonh px? 


*commonh px? 


*commonh px? 
Q
<Phase 2.2 Physical Synthesis In Placer | Checksum: ffbed883
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:01:50 ; elapsed = 00:00:52 . Memory (MB): peak = 4446.977 ; gain = 0.000 ; free physical = 1616 ; free virtual = 125242default:defaulth px? 
C
.Phase 2 Global Placement | Checksum: 365444cb
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:01:58 ; elapsed = 00:00:56 . Memory (MB): peak = 4446.977 ; gain = 0.000 ; free physical = 1618 ; free virtual = 125262default:defaulth px? 
q

Phase %s%s
101*constraints2
3 2default:default2$
Detail Placement2default:defaultZ18-101h px? 
}

Phase %s%s
101*constraints2
3.1 2default:default2.
Commit Multi Column Macros2default:defaultZ18-101h px? 
O
:Phase 3.1 Commit Multi Column Macros | Checksum: 365444cb
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:01:58 ; elapsed = 00:00:56 . Memory (MB): peak = 4446.977 ; gain = 0.000 ; free physical = 1618 ; free virtual = 125262default:defaulth px? 


Phase %s%s
101*constraints2
3.2 2default:default20
Commit Most Macros & LUTRAMs2default:defaultZ18-101h px? 
Q
<Phase 3.2 Commit Most Macros & LUTRAMs | Checksum: e552f5bf
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:02:01 ; elapsed = 00:00:58 . Memory (MB): peak = 4446.977 ; gain = 0.000 ; free physical = 1613 ; free virtual = 125212default:defaulth px? 
y

Phase %s%s
101*constraints2
3.3 2default:default2*
Area Swap Optimization2default:defaultZ18-101h px? 
L
7Phase 3.3 Area Swap Optimization | Checksum: 126e126f2
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:02:02 ; elapsed = 00:00:58 . Memory (MB): peak = 4446.977 ; gain = 0.000 ; free physical = 1613 ; free virtual = 125212default:defaulth px? 
s

Phase %s%s
101*constraints2
3.4 2default:default2$
IO Cut Optimizer2default:defaultZ18-101h px? 
E
0Phase 3.4 IO Cut Optimizer | Checksum: edd1e04b
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:02:02 ; elapsed = 00:00:58 . Memory (MB): peak = 4446.977 ; gain = 0.000 ; free physical = 1613 ; free virtual = 125212default:defaulth px? 
t

Phase %s%s
101*constraints2
3.5 2default:default2%
Fast Optimization2default:defaultZ18-101h px? 
F
1Phase 3.5 Fast Optimization | Checksum: cd970923
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:02:08 ; elapsed = 00:01:03 . Memory (MB): peak = 4446.977 ; gain = 0.000 ; free physical = 1610 ; free virtual = 125182default:defaulth px? 
y

Phase %s%s
101*constraints2
3.6 2default:default2*
Small Shape Clustering2default:defaultZ18-101h px? 
L
7Phase 3.6 Small Shape Clustering | Checksum: 1641706f0
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:02:10 ; elapsed = 00:01:03 . Memory (MB): peak = 4446.977 ; gain = 0.000 ; free physical = 1602 ; free virtual = 125092default:defaulth px? 


Phase %s%s
101*constraints2
3.7 2default:default20
Flow Legalize Slice Clusters2default:defaultZ18-101h px? 
R
=Phase 3.7 Flow Legalize Slice Clusters | Checksum: 101094603
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:02:10 ; elapsed = 00:01:04 . Memory (MB): peak = 4446.977 ; gain = 0.000 ; free physical = 1601 ; free virtual = 125092default:defaulth px? 
r

Phase %s%s
101*constraints2
3.8 2default:default2#
Slice Area Swap2default:defaultZ18-101h px? 
E
0Phase 3.8 Slice Area Swap | Checksum: 181260094
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:02:11 ; elapsed = 00:01:05 . Memory (MB): peak = 4446.977 ; gain = 0.000 ; free physical = 1581 ; free virtual = 124892default:defaulth px? 
x

Phase %s%s
101*constraints2
3.9 2default:default2)
Commit Slice Clusters2default:defaultZ18-101h px? 
K
6Phase 3.9 Commit Slice Clusters | Checksum: 1298e9395
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:02:15 ; elapsed = 00:01:06 . Memory (MB): peak = 4446.977 ; gain = 0.000 ; free physical = 1599 ; free virtual = 125072default:defaulth px? 
v

Phase %s%s
101*constraints2
3.10 2default:default2&
Re-assign LUT pins2default:defaultZ18-101h px? 
H
3Phase 3.10 Re-assign LUT pins | Checksum: dd4fbb4f
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:02:16 ; elapsed = 00:01:07 . Memory (MB): peak = 4446.977 ; gain = 0.000 ; free physical = 1598 ; free virtual = 125052default:defaulth px? 
?

Phase %s%s
101*constraints2
3.11 2default:default22
Pipeline Register Optimization2default:defaultZ18-101h px? 
T
?Phase 3.11 Pipeline Register Optimization | Checksum: eb631c76
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:02:16 ; elapsed = 00:01:07 . Memory (MB): peak = 4446.977 ; gain = 0.000 ; free physical = 1599 ; free virtual = 125072default:defaulth px? 
u

Phase %s%s
101*constraints2
3.12 2default:default2%
Fast Optimization2default:defaultZ18-101h px? 
G
2Phase 3.12 Fast Optimization | Checksum: fec8065e
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:02:35 ; elapsed = 00:01:18 . Memory (MB): peak = 4446.977 ; gain = 0.000 ; free physical = 1591 ; free virtual = 124992default:defaulth px? 
C
.Phase 3 Detail Placement | Checksum: fec8065e
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:02:36 ; elapsed = 00:01:18 . Memory (MB): peak = 4446.977 ; gain = 0.000 ; free physical = 1591 ; free virtual = 124992default:defaulth px? 
?

Phase %s%s
101*constraints2
4 2default:default2<
(Post Placement Optimization and Clean-Up2default:defaultZ18-101h px? 
{

Phase %s%s
101*constraints2
4.1 2default:default2,
Post Commit Optimization2default:defaultZ18-101h px? 
E
%Done setting XDC timing constraints.
35*timingZ38-35h px? 
?

Phase %s%s
101*constraints2
4.1.1 2default:default2/
Post Placement Optimization2default:defaultZ18-101h px? 
V
APost Placement Optimization Initialization | Checksum: 1bfe941a6
*commonh px? 
u

Phase %s%s
101*constraints2
4.1.1.1 2default:default2"
BUFG Insertion2default:defaultZ18-101h px? 
?
?BUFG insertion identified %s candidate nets, %s success, %s bufg driver replicated, %s skipped for placement/routing, %s skipped for timing, %s skipped for netlist change reason40*	placeflow2
02default:default2
02default:default2
02default:default2
02default:default2
02default:default2
02default:defaultZ46-46h px? 
H
3Phase 4.1.1.1 BUFG Insertion | Checksum: 1bfe941a6
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:02:54 ; elapsed = 00:01:23 . Memory (MB): peak = 4446.977 ; gain = 0.000 ; free physical = 1593 ; free virtual = 125012default:defaulth px? 
?
hPost Placement Timing Summary WNS=%s. For the most accurate timing information please run report_timing.610*place2
-0.3312default:defaultZ30-746h px? 
S
>Phase 4.1.1 Post Placement Optimization | Checksum: 1e6ec93ae
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:03:30 ; elapsed = 00:01:59 . Memory (MB): peak = 4446.977 ; gain = 0.000 ; free physical = 1590 ; free virtual = 124982default:defaulth px? 
N
9Phase 4.1 Post Commit Optimization | Checksum: 1e6ec93ae
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:03:30 ; elapsed = 00:01:59 . Memory (MB): peak = 4446.977 ; gain = 0.000 ; free physical = 1590 ; free virtual = 124982default:defaulth px? 
y

Phase %s%s
101*constraints2
4.2 2default:default2*
Post Placement Cleanup2default:defaultZ18-101h px? 
L
7Phase 4.2 Post Placement Cleanup | Checksum: 1e6ec93ae
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:03:34 ; elapsed = 00:02:01 . Memory (MB): peak = 4446.977 ; gain = 0.000 ; free physical = 1600 ; free virtual = 125082default:defaulth px? 
?
r%sTime (s): cpu = %s ; elapsed = %s . Memory (MB): peak = %s ; gain = %s ; free physical = %s ; free virtual = %s
480*common2.
Netlist sorting complete. 2default:default2
00:00:00.012default:default2
00:00:002default:default2
4446.9772default:default2
0.0002default:default2
15872default:default2
124952default:defaultZ17-722h px? 
s

Phase %s%s
101*constraints2
4.3 2default:default2$
Placer Reporting2default:defaultZ18-101h px? 
F
1Phase 4.3 Placer Reporting | Checksum: 1fd2394d9
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:03:41 ; elapsed = 00:02:08 . Memory (MB): peak = 4446.977 ; gain = 0.000 ; free physical = 1589 ; free virtual = 124972default:defaulth px? 
z

Phase %s%s
101*constraints2
4.4 2default:default2+
Final Placement Cleanup2default:defaultZ18-101h px? 
?
r%sTime (s): cpu = %s ; elapsed = %s . Memory (MB): peak = %s ; gain = %s ; free physical = %s ; free virtual = %s
480*common2.
Netlist sorting complete. 2default:default2
00:00:00.012default:default2
00:00:002default:default2
4446.9772default:default2
0.0002default:default2
15892default:default2
124972default:defaultZ17-722h px? 
M
8Phase 4.4 Final Placement Cleanup | Checksum: 1d616eeff
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:03:41 ; elapsed = 00:02:08 . Memory (MB): peak = 4446.977 ; gain = 0.000 ; free physical = 1589 ; free virtual = 124972default:defaulth px? 
\
GPhase 4 Post Placement Optimization and Clean-Up | Checksum: 1d616eeff
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:03:41 ; elapsed = 00:02:08 . Memory (MB): peak = 4446.977 ; gain = 0.000 ; free physical = 1588 ; free virtual = 124962default:defaulth px? 
>
)Ending Placer Task | Checksum: 18f798293
*commonh px? 
?

%s
*constraints2?
?Time (s): cpu = 00:03:41 ; elapsed = 00:02:08 . Memory (MB): peak = 4446.977 ; gain = 0.000 ; free physical = 1663 ; free virtual = 125712default:defaulth px? 
Z
Releasing license: %s
83*common2"
Implementation2default:defaultZ17-83h px? 
?
G%s Infos, %s Warnings, %s Critical Warnings and %s Errors encountered.
28*	vivadotcl2
792default:default2
1002default:default2
1022default:default2
02default:defaultZ4-41h px? 
^
%s completed successfully
29*	vivadotcl2 
place_design2default:defaultZ4-42h px? 
?
r%sTime (s): cpu = %s ; elapsed = %s . Memory (MB): peak = %s ; gain = %s ; free physical = %s ; free virtual = %s
480*common2"
place_design: 2default:default2
00:03:472default:default2
00:02:132default:default2
4446.9772default:default2
0.0002default:default2
16632default:default2
125712default:defaultZ17-722h px? 
?
r%sTime (s): cpu = %s ; elapsed = %s . Memory (MB): peak = %s ; gain = %s ; free physical = %s ; free virtual = %s
480*common2.
Netlist sorting complete. 2default:default2
00:00:00.012default:default2
00:00:00.012default:default2
4446.9772default:default2
0.0002default:default2
16632default:default2
125712default:defaultZ17-722h px? 
H
&Writing timing data to binary archive.266*timingZ38-480h px? 
D
Writing placer database...
1603*designutilsZ20-1893h px? 
?
r%sTime (s): cpu = %s ; elapsed = %s . Memory (MB): peak = %s ; gain = %s ; free physical = %s ; free virtual = %s
480*common2.
Netlist sorting complete. 2default:default2
00:00:00.012default:default2
00:00:002default:default2
4446.9772default:default2
0.0002default:default2
16542default:default2
125682default:defaultZ17-722h px? 
=
Writing XDEF routing.
211*designutilsZ20-211h px? 
J
#Writing XDEF routing logical nets.
209*designutilsZ20-209h px? 
J
#Writing XDEF routing special nets.
210*designutilsZ20-210h px? 
?
r%sTime (s): cpu = %s ; elapsed = %s . Memory (MB): peak = %s ; gain = %s ; free physical = %s ; free virtual = %s
480*common2)
Write XDEF Complete: 2default:default2
00:00:032default:default2
00:00:012default:default2
4446.9772default:default2
0.0002default:default2
16322default:default2
125662default:defaultZ17-722h px? 
?
 The %s '%s' has been generated.
621*common2

checkpoint2default:default2?
{/home/hp/projects/moj-pardaz/xilinx/vivado/Zynq_Serial_Port/Zynq_Serial_Port.runs/impl_1/Base_Zynq_MPSoC_wrapper_placed.dcp2default:defaultZ17-1381h px? 
?
r%sTime (s): cpu = %s ; elapsed = %s . Memory (MB): peak = %s ; gain = %s ; free physical = %s ; free virtual = %s
480*common2&
write_checkpoint: 2default:default2
00:00:082default:default2
00:00:062default:default2
4446.9772default:default2
0.0002default:default2
16522default:default2
125672default:defaultZ17-722h px? 
r
%s4*runtcl2V
BExecuting : report_io -file Base_Zynq_MPSoC_wrapper_io_placed.rpt
2default:defaulth px? 
?
?report_io: Time (s): cpu = 00:00:00.32 ; elapsed = 00:00:00.43 . Memory (MB): peak = 4446.977 ; gain = 0.000 ; free physical = 1626 ; free virtual = 12541
*commonh px? 
?
%s4*runtcl2?
?Executing : report_utilization -file Base_Zynq_MPSoC_wrapper_utilization_placed.rpt -pb Base_Zynq_MPSoC_wrapper_utilization_placed.pb
2default:defaulth px? 
?
%s4*runtcl2s
_Executing : report_control_sets -verbose -file Base_Zynq_MPSoC_wrapper_control_sets_placed.rpt
2default:defaulth px? 
?
?report_control_sets: Time (s): cpu = 00:00:00.10 ; elapsed = 00:00:00.21 . Memory (MB): peak = 4446.977 ; gain = 0.000 ; free physical = 1652 ; free virtual = 12566
*commonh px? 


End Record
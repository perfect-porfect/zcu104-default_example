connect -url tcp:127.0.0.1:3121
source /home/hp/softwares/xilinx/SDK/2018.3/scripts/sdk/util/zynqmp_utils.tcl
targets -set -nocase -filter {name =~"APU*" && jtag_cable_name =~ "Xilinx HW-Z1-ZCU104 FT4232H 93089A"} -index 1
rst -system
after 3000
targets -set -nocase -filter {name =~"APU*" && jtag_cable_name =~ "Xilinx HW-Z1-ZCU104 FT4232H 93089A"} -index 1
reset_apu
targets -set -nocase -filter {name =~"RPU*" && jtag_cable_name =~ "Xilinx HW-Z1-ZCU104 FT4232H 93089A"} -index 1
clear_rpu_reset
targets -set -nocase -filter {name =~"APU*" && jtag_cable_name =~ "Xilinx HW-Z1-ZCU104 FT4232H 93089A"} -index 1
loadhw -hw /home/hp/projects/vivado/zcu104-default_example/Zynq_Serial_Port.sdk/ZynqMP/system.hdf -mem-ranges [list {0x80000000 0xbfffffff} {0x400000000 0x5ffffffff} {0x1000000000 0x7fffffffff}]
configparams force-mem-access 1
targets -set -nocase -filter {name =~"APU*" && jtag_cable_name =~ "Xilinx HW-Z1-ZCU104 FT4232H 93089A"} -index 1
source /home/hp/projects/vivado/zcu104-default_example/Zynq_Serial_Port.sdk/ZynqMP/psu_init.tcl
psu_init
after 1000
psu_ps_pl_isolation_removal
after 1000
psu_ps_pl_reset_config
catch {psu_protection}
targets -set -nocase -filter {name =~"*A53*0" && jtag_cable_name =~ "Xilinx HW-Z1-ZCU104 FT4232H 93089A"} -index 1
rst -processor
dow /home/hp/projects/vivado/zcu104-default_example/Zynq_Serial_Port.sdk/core0_shared_memory/Debug/core0_shared_memory.elf
targets -set -nocase -filter {name =~"*A53*1" && jtag_cable_name =~ "Xilinx HW-Z1-ZCU104 FT4232H 93089A"} -index 1
rst -processor
dow /home/hp/projects/vivado/zcu104-default_example/Zynq_Serial_Port.sdk/core1_shared_memory/Debug/core1_shared_memory.elf
targets -set -nocase -filter {name =~"*A53*2" && jtag_cable_name =~ "Xilinx HW-Z1-ZCU104 FT4232H 93089A"} -index 1
rst -processor
dow /home/hp/projects/vivado/zcu104-default_example/Zynq_Serial_Port.sdk/core2_shared_memory/Debug/core2_shared_memory.elf
targets -set -nocase -filter {name =~"*A53*3" && jtag_cable_name =~ "Xilinx HW-Z1-ZCU104 FT4232H 93089A"} -index 1
rst -processor
dow /home/hp/projects/vivado/zcu104-default_example/Zynq_Serial_Port.sdk/core3_shared_memory/Debug/core3_shared_memory.elf
configparams force-mem-access 0
targets -set -nocase -filter {name =~"*A53*0" && jtag_cable_name =~ "Xilinx HW-Z1-ZCU104 FT4232H 93089A"} -index 1
con
targets -set -nocase -filter {name =~"*A53*1" && jtag_cable_name =~ "Xilinx HW-Z1-ZCU104 FT4232H 93089A"} -index 1
con
targets -set -nocase -filter {name =~"*A53*2" && jtag_cable_name =~ "Xilinx HW-Z1-ZCU104 FT4232H 93089A"} -index 1
con
targets -set -nocase -filter {name =~"*A53*3" && jtag_cable_name =~ "Xilinx HW-Z1-ZCU104 FT4232H 93089A"} -index 1
con

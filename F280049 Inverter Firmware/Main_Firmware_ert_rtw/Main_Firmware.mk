###########################################################################
## Makefile generated for component 'Main_Firmware'. 
## 
## Makefile     : Main_Firmware.mk
## Generated on : Fri Jul 25 03:10:58 2025
## Final product: $(RELATIVE_PATH_TO_ANCHOR)/Main_Firmware.out
## Product type : executable
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile

PRODUCT_NAME              = Main_Firmware
MAKEFILE                  = Main_Firmware.mk
MATLAB_ROOT               = C:/PROGRA~1/MATLAB/R2024b
MATLAB_BIN                = C:/PROGRA~1/MATLAB/R2024b/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/win64
START_DIR                 = C:/Users/minhp/ONEDRI~1/DOCUME~1/GitHub/CUSTOM~1/F28004~1
SOLVER                    = 
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
TGT_FCN_LIB               = TI C28x
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 0
RELATIVE_PATH_TO_ANCHOR   = ..
C_STANDARD_OPTS           = 
CPP_STANDARD_OPTS         = 

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          Texas Instruments Code Composer Studio (C2000)
# Supported Version(s):    
# ToolchainInfo Version:   2024b
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# CCSINSTALLDIR
# CCSSCRIPTINGDIR
# TARGET_LOAD_CMD_ARGS

#-----------
# MACROS
#-----------

TARGET_SCRIPTINGTOOLS_INSTALLDIR = $(CCSSCRIPTINGDIR)
TI_C2000_SHARED_DIR              = $(MATLAB_ROOT)/toolbox/c2b/tic2000_shared
TI_TOOLS                         = $(CCSINSTALLDIR)/bin
TI_INCLUDE                       = $(CCSINSTALLDIR)/include
TI_LIB                           = $(CCSINSTALLDIR)/lib
CCOUTPUTFLAG                     = --output_file=
LDOUTPUTFLAG                     = --output_file=
EXE_FILE_EXT                     = $(PROGRAM_FILE_EXT)
PRODUCT_HEX                      = $(RELATIVE_PATH_TO_ANCHOR)/$(PRODUCT_NAME).hex
PRODUCT_DWO                      = $(RELATIVE_PATH_TO_ANCHOR)/$(PRODUCT_NAME).dwo
PRODUCT_ELF                      = $(RELATIVE_PATH_TO_ANCHOR)/$(PRODUCT_NAME).elf
DOWN_EXE_JS                      = $(TARGET_PKG_INSTALLDIR)/tic2000/CCS_Config/runProgram_generic.js
CCS_CONFIG                       = $(TARGET_PKG_INSTALLDIR)/tic2000/CCS_Config/f28x_generic.ccxml
PRODUCT_DEP                      = $(PRODUCT_NAME).txt
DEPFILE_UPDATE                   = $(TI_C2000_SHARED_DIR)/tools/PostBuildDepedency/win64/DepedencyFileUpdate.ps1
SHELL                            = %SystemRoot%/system32/cmd.exe

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = 

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# Assembler: C2000 Assembler
AS_PATH = $(TI_TOOLS)
AS = "$(AS_PATH)/cl2000"

# C Compiler: C2000 C Compiler
CC_PATH = $(TI_TOOLS)
CC = "$(CC_PATH)/cl2000"

# Linker: C2000 Linker
LD_PATH = $(TI_TOOLS)
LD = "$(LD_PATH)/cl2000"

# C++ Compiler: C2000 C++ Compiler
CPP_PATH = $(TI_TOOLS)
CPP = "$(CPP_PATH)/cl2000"

# C++ Linker: C2000 C++ Linker
CPP_LD_PATH = $(TI_TOOLS)
CPP_LD = "$(CPP_LD_PATH)/cl2000"

# Archiver: C2000 Archiver
AR_PATH = $(TI_TOOLS)
AR = "$(AR_PATH)/ar2000"

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)/mex"

# Hex Converter: Hex Converter

# DWO Converter: DWO Converter

# Download: Download
DOWNLOAD_PATH = $(TARGET_SCRIPTINGTOOLS_INSTALLDIR)/bin
DOWNLOAD = "$(DOWNLOAD_PATH)/dss.bat"

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: GMAKE Utility
MAKE_PATH = %MATLAB%\bin\win64
MAKE = "$(MAKE_PATH)/gmake"


#-------------------------
# Directives/Utilities
#-------------------------

ASDEBUG             = -g
AS_OUTPUT_FLAG      = --output_file=
CDEBUG              = -g
C_OUTPUT_FLAG       = --output_file=
LDDEBUG             =
OUTPUT_FLAG         = --output_file=
CPPDEBUG            = -g
CPP_OUTPUT_FLAG     = --output_file=
CPPLDDEBUG          =
OUTPUT_FLAG         = --output_file=
ARDEBUG             =
STATICLIB_OUTPUT_FLAG =
MEX_DEBUG           = -g
RM                  = @del /F
ECHO                = @echo
MV                  = @move
RUN                 =

#----------------------------------------
# "Faster Builds" Build Configuration
#----------------------------------------

MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =



#---------------------------
# Model-Specific Options
#---------------------------

ASFLAGS = --abi=coffabi -s -v28 -ml $(ASFLAGS_ADDITIONAL)

CFLAGS = --abi=coffabi --compile_only --preproc_dependency="$(@:%.obj=%.dep)" --preproc_with_compile  -I"$(TI_INCLUDE)" --large_memory_model --silicon_version=28 --define="LARGE_MODEL" -g

LDFLAGS = --abi=coffabi -z -I$(TI_LIB) --stack_size=$(STACK_SIZE) --warn_sections --heap_size=$(HEAP_SIZE) --reread_libs --rom_model --priority -m"$(PRODUCT_NAME).map"

SHAREDLIB_LDFLAGS = 

CPPFLAGS = -g

CPP_LDFLAGS = 

CPP_SHAREDLIB_LDFLAGS = 

ARFLAGS = -r

OBJCOPYFLAGS_HEX = -i "$<" -o "$@" -order MS -romwidth 16 -q

OBJCOPYFLAGS_DWO = "$<"

DOWNLOAD_FLAGS = $(TARGET_LOAD_CMD_ARGS) $(PRODUCT)

EXECUTE_FLAGS = 

MAKE_FLAGS = -f $(MAKEFILE)

###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = $(RELATIVE_PATH_TO_ANCHOR)/Main_Firmware.out
PRODUCT_TYPE = "executable"
BUILD_TYPE = "Top-Level Standalone Executable"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = -I$(START_DIR) -I$(START_DIR)/Main_Firmware_ert_rtw -I$(MATLAB_ROOT)/extern/include -I$(MATLAB_ROOT)/simulink/include -I$(MATLAB_ROOT)/rtw/c/src -I$(MATLAB_ROOT)/rtw/c/src/ext_mode/common -I$(MATLAB_ROOT)/rtw/c/ert -I$(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/include -I$(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/common -I$(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/protocol/src -I$(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/protocol/include -I$(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/transport/include -I$(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/transport/src -I$(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/platform/include -I$(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/platform/default -I$(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/include -I$(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src -I$(MATLAB_ROOT)/toolbox/coder/rtiostream/src -I$(MATLAB_ROOT)/toolbox/c2b/tic2000/inc -I$(MATLAB_ROOT)/toolbox/shared/can/src/scanutil -I$(MATLAB_ROOT)/toolbox/c2b/tic2000/src -I$(MATLAB_ROOT)/toolbox/c2b/tic2000_shared/src -I$(MATLAB_ROOT)/toolbox/c2b/tic2000_shared/inc -IC:/ti/C2000Ware_MotorControl_SDK_5_03_00_00/c2000ware/device_support/f28004x/common/include -IC:/ti/C2000Ware_MotorControl_SDK_5_03_00_00/c2000ware/libraries/calibration/hrpwm/f28004x/include -IC:/ti/C2000Ware_MotorControl_SDK_5_03_00_00/c2000ware/driverlib/f28004x/driverlib -IC:/ti/C2000Ware_MotorControl_SDK_5_03_00_00/c2000ware/driverlib/f28004x/driverlib/inc -IC:/ti/C2000Ware_MotorControl_SDK_5_03_00_00/c2000ware/device_support/f28004x/headers/include -IC:/ti/C2000Ware_MotorControl_SDK_5_03_00_00/c2000ware/device_support/f28004x/common -IC:/ti/C2000Ware_MotorControl_SDK_5_03_00_00/c2000ware/libraries/math/IQmath/c28/include -IC:/ti/C2000Ware_MotorControl_SDK_5_03_00_00/c2000ware/libraries/math/CLAmath/c28/include -I$(MATLAB_ROOT)/toolbox/c2b/tic2000_soc/src/ipclite -I$(MATLAB_ROOT)/toolbox/c2b/tic2000_soc/inc/ipclite

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_ = -DXCP_ADDRESS_GRANULARITY=XCP_ADDRESS_GRANULARITY_WORD -DCODERTARGET_XCP_DAQ_PACKED_MODE -DCODERTARGET_XCP_MAX_CONTIGUOUS_SAMPLES=8 -D__MW_TARGET_USE_HARDWARE_RESOURCES_H__
DEFINES_BUILD_ARGS = -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DEXT_MODE=1 -DINTEGER_CODE=0 -DMT=1
DEFINES_CUSTOM = 
DEFINES_OPTS = -DXCP_EXTMODE_SIMULATION_TIME_IN_TICKS -DXCP_DAQ_SUPPORT -DXCP_CALIBRATION_SUPPORT -DXCP_TIMESTAMP_SUPPORT -DXCP_TIMESTAMP_BASED_ON_SIMULATION_TIME -DXCP_SET_MTA_SUPPORT -DEXTMODE_XCP_TRIGGER_SUPPORT -DXCP_MEM_BLOCK_1_SIZE=32 -DXCP_MEM_BLOCK_1_NUMBER=1 -DXCP_MEM_BLOCK_2_SIZE=56 -DXCP_MEM_BLOCK_2_NUMBER=1 -DXCP_MEM_BLOCK_3_SIZE=184 -DXCP_MEM_BLOCK_3_NUMBER=1 -DXCP_MEM_RESERVED_POOLS_TOTAL_SIZE=4357 -DXCP_MEM_RESERVED_POOLS_NUMBER=2 -DXCP_MEM_DAQ_RESERVED_POOL_BLOCKS_NUMBER=3 -DXCP_MEM_DAQ_RESERVED_POOLS_NUMBER=1 -DXCP_MIN_EVENT_NO_RESERVED_POOL=3 -DXCP_MAX_CTO_SIZE=32 -DXCP_MAX_DTO_SIZE=65532 -DXCP_MAX_ODT_ENTRY_SIZE=255 -DEXTMODE_STATIC -DEXTMODE_STATIC_SIZE=5000 -DON_TARGET_WAIT_FOR_START=0 -DTID01EQ=1
DEFINES_SKIPFORSIL = -DXCP_CUSTOM_PLATFORM -DEXTMODE_DISABLE_ARGS_PROCESSING=1 -DMW_PIL_SCIFIFOLEN=16 -DCPU1 -DF2837X_REG_FORMAT -DMW_F28004X -DSTACK_SIZE=1024 -DRT -DF280049C -DBOOT_FROM_FLASH=1 -DCPU_RAMLS_DATA_START=0x9000 -DCPU_RAMLS_DATA_LENGTH=0x1800 -DCPU_RAMLS_PROG_START=0xB000 -DCPU_RAMLS_PROG_LENGTH=0x1000 -DCLA_RAMLS_PROG_START=0xA800 -DCLA_RAMLS_PROG_LENGTH=0x800 -DCLA_RAMLS_DATA_START=0x8000 -DCLA_RAMLS_DATA_LENGTH=0x1000
DEFINES_STANDARD = -DMODEL=Main_Firmware -DNUMST=3 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0

DEFINES = $(DEFINES_) $(DEFINES_BUILD_ARGS) $(DEFINES_CUSTOM) $(DEFINES_OPTS) $(DEFINES_SKIPFORSIL) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/xcp_ext_mode.c $(START_DIR)/Main_Firmware_ert_rtw/MW_c28xx_csl.c $(START_DIR)/Main_Firmware_ert_rtw/MW_c28xx_board.c $(START_DIR)/Main_Firmware_ert_rtw/MW_c28xx_adc.c $(START_DIR)/Main_Firmware_ert_rtw/MW_c28xx_overrun.c $(START_DIR)/Main_Firmware_ert_rtw/MW_c28xx_pwm.c $(START_DIR)/Main_Firmware_ert_rtw/Main_Firmware.c $(START_DIR)/Main_Firmware_ert_rtw/Main_Firmware_data.c $(START_DIR)/Main_Firmware_ert_rtw/rtGetInf.c $(START_DIR)/Main_Firmware_ert_rtw/rtGetNaN.c $(START_DIR)/Main_Firmware_ert_rtw/rt_nonfinite.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/xcp_ext_common.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/xcp_ext_classic_trigger.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/protocol/src/xcp.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/protocol/src/xcp_standard.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/protocol/src/xcp_daq.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/protocol/src/xcp_calibration.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/transport/src/xcp_fifo.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/transport/src/xcp_transport.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/platform/default/xcp_mem_default.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/platform/default/xcp_drv_rtiostream.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/common/xcp_utils.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/transport/src/xcp_frame_serial.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/xcp_ext_param_default_serial.c $(MATLAB_ROOT)/toolbox/c2b/tic2000/src/c28004xBoard_Realtime_Support.c $(MATLAB_ROOT)/toolbox/c2b/tic2000_shared/src/MW_c28xGlobalInterrupts.c C:/ti/C2000Ware_MotorControl_SDK_5_03_00_00/c2000ware/device_support/f28004x/common/source/f28004x_cputimers.c C:/ti/C2000Ware_MotorControl_SDK_5_03_00_00/c2000ware/device_support/f28004x/common/source/f28004x_defaultisr.c C:/ti/C2000Ware_MotorControl_SDK_5_03_00_00/c2000ware/device_support/f28004x/headers/source/f28004x_globalvariabledefs.c C:/ti/C2000Ware_MotorControl_SDK_5_03_00_00/c2000ware/device_support/f28004x/common/source/f28004x_piectrl.c C:/ti/C2000Ware_MotorControl_SDK_5_03_00_00/c2000ware/device_support/f28004x/common/source/f28004x_pievect.c C:/ti/C2000Ware_MotorControl_SDK_5_03_00_00/c2000ware/device_support/f28004x/common/source/f28004x_sysctrl.c $(MATLAB_ROOT)/toolbox/c2b/tic2000/src/MW_f28004x_usdelay.asm C:/ti/C2000Ware_MotorControl_SDK_5_03_00_00/c2000ware/device_support/f28004x/common/source/f28004x_codestartbranch.asm C:/ti/C2000Ware_MotorControl_SDK_5_03_00_00/c2000ware/device_support/f28004x/common/source/f28004x_gpio.c C:/ti/C2000Ware_MotorControl_SDK_5_03_00_00/c2000ware/device_support/f28004x/common/source/f28004x_adc.c C:/ti/C2000Ware_MotorControl_SDK_5_03_00_00/c2000ware/driverlib/f28004x/driverlib/sysctl.c C:/ti/C2000Ware_MotorControl_SDK_5_03_00_00/c2000ware/driverlib/f28004x/driverlib/dma.c C:/ti/C2000Ware_MotorControl_SDK_5_03_00_00/c2000ware/driverlib/f28004x/driverlib/clb.c $(MATLAB_ROOT)/toolbox/c2b/tic2000_shared/src/MW_c28xGPIO.c $(MATLAB_ROOT)/toolbox/c2b/tic2000/src/c2000HardwareTimerConfig.c $(MATLAB_ROOT)/toolbox/c2b/tic2000/src/c28004xSchedulerTimer0.c $(MATLAB_ROOT)/toolbox/c2b/tic2000_shared/src/rtiostream_serial_c28x.c $(MATLAB_ROOT)/toolbox/c2b/tic2000_shared/src/datamodify_xcp.c $(MATLAB_ROOT)/toolbox/c2b/tic2000/src/c2000HardwareTimerSupport.c $(MATLAB_ROOT)/toolbox/c2b/tic2000_soc/src/ipclite/mw_soc_c2000_ipc.c

MAIN_SRC = $(START_DIR)/Main_Firmware_ert_rtw/ert_main.c

ALL_SRCS = $(SRCS) $(MAIN_SRC)

###########################################################################
## OBJECTS
###########################################################################

OBJS = xcp_ext_mode.obj MW_c28xx_csl.obj MW_c28xx_board.obj MW_c28xx_adc.obj MW_c28xx_overrun.obj MW_c28xx_pwm.obj Main_Firmware.obj Main_Firmware_data.obj rtGetInf.obj rtGetNaN.obj rt_nonfinite.obj xcp_ext_common.obj xcp_ext_classic_trigger.obj xcp.obj xcp_standard.obj xcp_daq.obj xcp_calibration.obj xcp_fifo.obj xcp_transport.obj xcp_mem_default.obj xcp_drv_rtiostream.obj xcp_utils.obj xcp_frame_serial.obj xcp_ext_param_default_serial.obj c28004xBoard_Realtime_Support.obj MW_c28xGlobalInterrupts.obj f28004x_cputimers.obj f28004x_defaultisr.obj f28004x_globalvariabledefs.obj f28004x_piectrl.obj f28004x_pievect.obj f28004x_sysctrl.obj MW_f28004x_usdelay.obj f28004x_codestartbranch.obj f28004x_gpio.obj f28004x_adc.obj sysctl.obj dma.obj clb.obj MW_c28xGPIO.obj c2000HardwareTimerConfig.obj c28004xSchedulerTimer0.obj rtiostream_serial_c28x.obj datamodify_xcp.obj c2000HardwareTimerSupport.obj mw_soc_c2000_ipc.obj

MAIN_OBJ = ert_main.obj

ALL_OBJS = $(OBJS) $(MAIN_OBJ)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = C:/ti/C2000Ware_MotorControl_SDK_5_03_00_00/c2000ware/libraries/math/IQmath/c28/lib/IQmath_fpu32.lib $(MATLAB_ROOT)/toolbox/c2b/tic2000/src/c28004xPeripherals.cmd $(MATLAB_ROOT)/toolbox/c2b/tic2000/src/c280049M.cmd

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS = 

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_ =  --define="EXTMODE_DISABLEPRINTF" 
CFLAGS_SKIPFORSIL = -v28 --float_support=fpu32 -ml -DF280049C -DCPU1 -DBOOT_FROM_FLASH=1 --tmu_support=tmu0 --fp_mode=relaxed -DCPU_RAMLS_DATA_START=0x9000 -DCPU_RAMLS_DATA_LENGTH=0x1800 -DCPU_RAMLS_PROG_START=0xB000 -DCPU_RAMLS_PROG_LENGTH=0x1000 -DCLA_RAMLS_PROG_START=0xA800 -DCLA_RAMLS_PROG_LENGTH=0x800 -DCLA_RAMLS_DATA_START=0x8000 -DCLA_RAMLS_DATA_LENGTH=0x1000
CFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CFLAGS += $(CFLAGS_) $(CFLAGS_SKIPFORSIL) $(CFLAGS_BASIC)

#-----------
# Linker
#-----------

LDFLAGS_ = -l"rts2800_fpu32.lib"
LDFLAGS_SKIPFORSIL = --define F280049C --define CPU1 --define BOOT_FROM_FLASH=1 --define BOOT_USING_BL=0 --define CPU_RAMLS_DATA_START=0x9000 --define CPU_RAMLS_DATA_LENGTH=0x1800 --define CPU_RAMLS_PROG_START=0xB000 --define CPU_RAMLS_PROG_LENGTH=0x1000 --define CLA_RAMLS_PROG_START=0xA800 --define CLA_RAMLS_PROG_LENGTH=0x800 --define CLA_RAMLS_DATA_START=0x8000 --define CLA_RAMLS_DATA_LENGTH=0x1000

LDFLAGS += $(LDFLAGS_) $(LDFLAGS_SKIPFORSIL)

#--------------------------
# Shared Library Linker
#--------------------------

SHAREDLIB_LDFLAGS_ = -l"rts2800_fpu32.lib"
SHAREDLIB_LDFLAGS_SKIPFORSIL = --define F280049C --define CPU1 --define BOOT_FROM_FLASH=1 --define BOOT_USING_BL=0 --define CPU_RAMLS_DATA_START=0x9000 --define CPU_RAMLS_DATA_LENGTH=0x1800 --define CPU_RAMLS_PROG_START=0xB000 --define CPU_RAMLS_PROG_LENGTH=0x1000 --define CLA_RAMLS_PROG_START=0xA800 --define CLA_RAMLS_PROG_LENGTH=0x800 --define CLA_RAMLS_DATA_START=0x8000 --define CLA_RAMLS_DATA_LENGTH=0x1000

SHAREDLIB_LDFLAGS += $(SHAREDLIB_LDFLAGS_) $(SHAREDLIB_LDFLAGS_SKIPFORSIL)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_ =  --define="EXTMODE_DISABLEPRINTF" 
CPPFLAGS_SKIPFORSIL = -v28 --float_support=fpu32 -ml -DF280049C -DCPU1 -DBOOT_FROM_FLASH=1 --tmu_support=tmu0 --fp_mode=relaxed -DCPU_RAMLS_DATA_START=0x9000 -DCPU_RAMLS_DATA_LENGTH=0x1800 -DCPU_RAMLS_PROG_START=0xB000 -DCPU_RAMLS_PROG_LENGTH=0x1000 -DCLA_RAMLS_PROG_START=0xA800 -DCLA_RAMLS_PROG_LENGTH=0x800 -DCLA_RAMLS_DATA_START=0x8000 -DCLA_RAMLS_DATA_LENGTH=0x1000
CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CPPFLAGS += $(CPPFLAGS_) $(CPPFLAGS_SKIPFORSIL) $(CPPFLAGS_BASIC)

#---------------
# C++ Linker
#---------------

CPP_LDFLAGS_ = -l"rts2800_fpu32.lib"
CPP_LDFLAGS_SKIPFORSIL = --define F280049C --define CPU1 --define BOOT_FROM_FLASH=1 --define BOOT_USING_BL=0 --define CPU_RAMLS_DATA_START=0x9000 --define CPU_RAMLS_DATA_LENGTH=0x1800 --define CPU_RAMLS_PROG_START=0xB000 --define CPU_RAMLS_PROG_LENGTH=0x1000 --define CLA_RAMLS_PROG_START=0xA800 --define CLA_RAMLS_PROG_LENGTH=0x800 --define CLA_RAMLS_DATA_START=0x8000 --define CLA_RAMLS_DATA_LENGTH=0x1000

CPP_LDFLAGS += $(CPP_LDFLAGS_) $(CPP_LDFLAGS_SKIPFORSIL)

#------------------------------
# C++ Shared Library Linker
#------------------------------

CPP_SHAREDLIB_LDFLAGS_ = -l"rts2800_fpu32.lib"
CPP_SHAREDLIB_LDFLAGS_SKIPFORSIL = --define F280049C --define CPU1 --define BOOT_FROM_FLASH=1 --define BOOT_USING_BL=0 --define CPU_RAMLS_DATA_START=0x9000 --define CPU_RAMLS_DATA_LENGTH=0x1800 --define CPU_RAMLS_PROG_START=0xB000 --define CPU_RAMLS_PROG_LENGTH=0x1000 --define CLA_RAMLS_PROG_START=0xA800 --define CLA_RAMLS_PROG_LENGTH=0x800 --define CLA_RAMLS_DATA_START=0x8000 --define CLA_RAMLS_DATA_LENGTH=0x1000

CPP_SHAREDLIB_LDFLAGS += $(CPP_SHAREDLIB_LDFLAGS_) $(CPP_SHAREDLIB_LDFLAGS_SKIPFORSIL)

###########################################################################
## INLINED COMMANDS
###########################################################################


#-------------------------------------------
# Post build updates - DEP, HEX, DWO/ELF
#-------------------------------------------
all :
ifeq ($(DEPRULES),1)
#--------------------------
# Dependency file updates
#--------------------------
postbuild : $(PRODUCT_DEP)

$(PRODUCT_DEP): $(PRODUCT)
	@echo "### Updating dependency files ..."
	PowerShell -ExecutionPolicy Bypass -command "& '$(DEPFILE_UPDATE)'"
	@echo "### Done Updating dependency files ..."
endif

ifeq ($(PRODUCT_TYPE),"executable")
#--------------------------
# ELF to hex converter
#--------------------------
postbuild : $(PRODUCT_HEX)

$(PRODUCT_HEX): $(PRODUCT)
	@echo "### Invoking postbuild tool "Hex Converter" on "$<"..."
	$(CCSINSTALLDIR)/bin/hex2000 $(OBJCOPYFLAGS_HEX)
	@echo "### Done Invoking postbuild tool "Hex Converter" ..."

#--------------------------
# DWO converter
#--------------------------
postbuild : $(PRODUCT_DWO)

$(PRODUCT_DWO): $(PRODUCT)
	@echo "### Invoking postbuild tool "DWO Converter" on "$<"..."
	$(TI_C2000_SHARED_DIR)/tools/bin/win64/extractDWARF.exe $(OBJCOPYFLAGS_DWO)
	@echo "### Done Invoking postbuild tool "DWO Converter" ..."

endif

#--------------------------
# Dependency based build rule
#--------------------------
ifeq ($(DEPRULES),1) 
ALL_DEPS:=$(patsubst %.obj,%.d,$(ALL_OBJS))
all:
else
ALL_DEPS:=
endif




-include codertarget_assembly_flags.mk
-include ../codertarget_assembly_flags.mk
-include ../../codertarget_assembly_flags.mk
-include $(ALL_DEPS)


###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build buildobj clean info prebuild postbuild download execute


all : build postbuild
	@echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


buildobj : prebuild $(OBJS) $(PREBUILT_OBJS) $(LIBS)
	@echo "### Successfully generated all binary outputs."


prebuild : 


postbuild : $(PRODUCT)


download : postbuild
	@echo "### Invoking postbuild tool "Download" ..."
	$(DOWNLOAD) $(DOWNLOAD_FLAGS)
	@echo "### Done invoking postbuild tool."


execute : download
	@echo "### Invoking postbuild tool "Execute" ..."
	$(EXECUTE) $(EXECUTE_FLAGS)
	@echo "### Done invoking postbuild tool."


###########################################################################
## FINAL TARGET
###########################################################################

#-------------------------------------------
# Create a standalone executable            
#-------------------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS) $(LIBS) $(MAIN_OBJ)
	@echo "### Creating standalone executable "$(PRODUCT)" ..."
	$(LD) $(LDFLAGS) --output_file=$(PRODUCT) $(OBJS) $(MAIN_OBJ) $(LIBS) $(SYSTEM_LIBS) $(TOOLCHAIN_LIBS)
	@echo "### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.obj : %.cla
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : %.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : %.asm
	$(AS) $(ASFLAGS) --output_file="$@" "$<"


%.obj : %.cpp
	$(CPP) $(CPPFLAGS) --output_file="$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.cla
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.asm
	$(AS) $(ASFLAGS) --output_file="$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) $(CPPFLAGS) --output_file="$@" "$<"


%.obj : $(START_DIR)/%.cla
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(START_DIR)/%.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(START_DIR)/%.asm
	$(AS) $(ASFLAGS) --output_file="$@" "$<"


%.obj : $(START_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) --output_file="$@" "$<"


%.obj : $(START_DIR)/Main_Firmware_ert_rtw/%.cla
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(START_DIR)/Main_Firmware_ert_rtw/%.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(START_DIR)/Main_Firmware_ert_rtw/%.asm
	$(AS) $(ASFLAGS) --output_file="$@" "$<"


%.obj : $(START_DIR)/Main_Firmware_ert_rtw/%.cpp
	$(CPP) $(CPPFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/rtw/c/src/%.cla
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/rtw/c/src/%.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/rtw/c/src/%.asm
	$(AS) $(ASFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/rtw/c/src/%.cpp
	$(CPP) $(CPPFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/simulink/src/%.cla
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/simulink/src/%.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/simulink/src/%.asm
	$(AS) $(ASFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/simulink/src/%.cpp
	$(CPP) $(CPPFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.cla
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.asm
	$(AS) $(ASFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.cpp
	$(CPP) $(CPPFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/protocol/src/%.cla
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/protocol/src/%.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/protocol/src/%.asm
	$(AS) $(ASFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/protocol/src/%.cpp
	$(CPP) $(CPPFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/transport/src/%.cla
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/transport/src/%.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/transport/src/%.asm
	$(AS) $(ASFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/transport/src/%.cpp
	$(CPP) $(CPPFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/%.cla
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/%.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/%.asm
	$(AS) $(ASFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/%.cpp
	$(CPP) $(CPPFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/common/%.cla
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/common/%.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/common/%.asm
	$(AS) $(ASFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/common/%.cpp
	$(CPP) $(CPPFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/platform/default/%.cla
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/platform/default/%.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/platform/default/%.asm
	$(AS) $(ASFLAGS) --output_file="$@" "$<"


%.obj : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/platform/default/%.cpp
	$(CPP) $(CPPFLAGS) --output_file="$@" "$<"


xcp_ext_mode.obj : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/xcp_ext_mode.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


MW_c28xx_csl.obj : $(START_DIR)/Main_Firmware_ert_rtw/MW_c28xx_csl.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


MW_c28xx_board.obj : $(START_DIR)/Main_Firmware_ert_rtw/MW_c28xx_board.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


MW_c28xx_adc.obj : $(START_DIR)/Main_Firmware_ert_rtw/MW_c28xx_adc.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


MW_c28xx_overrun.obj : $(START_DIR)/Main_Firmware_ert_rtw/MW_c28xx_overrun.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


MW_c28xx_pwm.obj : $(START_DIR)/Main_Firmware_ert_rtw/MW_c28xx_pwm.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


Main_Firmware.obj : $(START_DIR)/Main_Firmware_ert_rtw/Main_Firmware.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


Main_Firmware_data.obj : $(START_DIR)/Main_Firmware_ert_rtw/Main_Firmware_data.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


ert_main.obj : $(START_DIR)/Main_Firmware_ert_rtw/ert_main.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


rtGetInf.obj : $(START_DIR)/Main_Firmware_ert_rtw/rtGetInf.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


rtGetNaN.obj : $(START_DIR)/Main_Firmware_ert_rtw/rtGetNaN.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


rt_nonfinite.obj : $(START_DIR)/Main_Firmware_ert_rtw/rt_nonfinite.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


xcp_ext_common.obj : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/xcp_ext_common.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


xcp_ext_classic_trigger.obj : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/xcp_ext_classic_trigger.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


xcp.obj : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/protocol/src/xcp.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


xcp_standard.obj : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/protocol/src/xcp_standard.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


xcp_daq.obj : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/protocol/src/xcp_daq.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


xcp_calibration.obj : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/protocol/src/xcp_calibration.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


xcp_fifo.obj : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/transport/src/xcp_fifo.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


xcp_transport.obj : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/transport/src/xcp_transport.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


xcp_mem_default.obj : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/platform/default/xcp_mem_default.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


xcp_drv_rtiostream.obj : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/platform/default/xcp_drv_rtiostream.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


xcp_utils.obj : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/common/xcp_utils.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


xcp_frame_serial.obj : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/transport/src/xcp_frame_serial.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


xcp_ext_param_default_serial.obj : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/xcp_ext_param_default_serial.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


c28004xBoard_Realtime_Support.obj : $(MATLAB_ROOT)/toolbox/c2b/tic2000/src/c28004xBoard_Realtime_Support.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


MW_c28xGlobalInterrupts.obj : $(MATLAB_ROOT)/toolbox/c2b/tic2000_shared/src/MW_c28xGlobalInterrupts.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


f28004x_cputimers.obj : C:/ti/C2000Ware_MotorControl_SDK_5_03_00_00/c2000ware/device_support/f28004x/common/source/f28004x_cputimers.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


f28004x_defaultisr.obj : C:/ti/C2000Ware_MotorControl_SDK_5_03_00_00/c2000ware/device_support/f28004x/common/source/f28004x_defaultisr.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


f28004x_globalvariabledefs.obj : C:/ti/C2000Ware_MotorControl_SDK_5_03_00_00/c2000ware/device_support/f28004x/headers/source/f28004x_globalvariabledefs.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


f28004x_piectrl.obj : C:/ti/C2000Ware_MotorControl_SDK_5_03_00_00/c2000ware/device_support/f28004x/common/source/f28004x_piectrl.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


f28004x_pievect.obj : C:/ti/C2000Ware_MotorControl_SDK_5_03_00_00/c2000ware/device_support/f28004x/common/source/f28004x_pievect.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


f28004x_sysctrl.obj : C:/ti/C2000Ware_MotorControl_SDK_5_03_00_00/c2000ware/device_support/f28004x/common/source/f28004x_sysctrl.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


MW_f28004x_usdelay.obj : $(MATLAB_ROOT)/toolbox/c2b/tic2000/src/MW_f28004x_usdelay.asm
	$(AS) $(ASFLAGS) --output_file="$@" "$<"


f28004x_codestartbranch.obj : C:/ti/C2000Ware_MotorControl_SDK_5_03_00_00/c2000ware/device_support/f28004x/common/source/f28004x_codestartbranch.asm
	$(AS) $(ASFLAGS) --output_file="$@" "$<"


f28004x_gpio.obj : C:/ti/C2000Ware_MotorControl_SDK_5_03_00_00/c2000ware/device_support/f28004x/common/source/f28004x_gpio.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


f28004x_adc.obj : C:/ti/C2000Ware_MotorControl_SDK_5_03_00_00/c2000ware/device_support/f28004x/common/source/f28004x_adc.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


sysctl.obj : C:/ti/C2000Ware_MotorControl_SDK_5_03_00_00/c2000ware/driverlib/f28004x/driverlib/sysctl.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


dma.obj : C:/ti/C2000Ware_MotorControl_SDK_5_03_00_00/c2000ware/driverlib/f28004x/driverlib/dma.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


clb.obj : C:/ti/C2000Ware_MotorControl_SDK_5_03_00_00/c2000ware/driverlib/f28004x/driverlib/clb.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


MW_c28xGPIO.obj : $(MATLAB_ROOT)/toolbox/c2b/tic2000_shared/src/MW_c28xGPIO.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


c2000HardwareTimerConfig.obj : $(MATLAB_ROOT)/toolbox/c2b/tic2000/src/c2000HardwareTimerConfig.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


c28004xSchedulerTimer0.obj : $(MATLAB_ROOT)/toolbox/c2b/tic2000/src/c28004xSchedulerTimer0.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


rtiostream_serial_c28x.obj : $(MATLAB_ROOT)/toolbox/c2b/tic2000_shared/src/rtiostream_serial_c28x.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


datamodify_xcp.obj : $(MATLAB_ROOT)/toolbox/c2b/tic2000_shared/src/datamodify_xcp.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


c2000HardwareTimerSupport.obj : $(MATLAB_ROOT)/toolbox/c2b/tic2000/src/c2000HardwareTimerSupport.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


mw_soc_c2000_ipc.obj : $(MATLAB_ROOT)/toolbox/c2b/tic2000_soc/src/ipclite/mw_soc_c2000_ipc.c
	$(CC) $(CFLAGS) --output_file="$@" "$<"


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(MAKEFILE)


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@echo "### PRODUCT = $(PRODUCT)"
	@echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@echo "### BUILD_TYPE = $(BUILD_TYPE)"
	@echo "### INCLUDES = $(INCLUDES)"
	@echo "### DEFINES = $(DEFINES)"
	@echo "### ALL_SRCS = $(ALL_SRCS)"
	@echo "### ALL_OBJS = $(ALL_OBJS)"
	@echo "### LIBS = $(LIBS)"
	@echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	@echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@echo "### ASFLAGS = $(ASFLAGS)"
	@echo "### CFLAGS = $(CFLAGS)"
	@echo "### LDFLAGS = $(LDFLAGS)"
	@echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@echo "### CPPFLAGS = $(CPPFLAGS)"
	@echo "### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	@echo "### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	@echo "### ARFLAGS = $(ARFLAGS)"
	@echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	@echo "### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	@echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@echo "### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	@echo "### OBJCOPYFLAGS_HEX = $(OBJCOPYFLAGS_HEX)"
	@echo "### OBJCOPYFLAGS_DWO = $(OBJCOPYFLAGS_DWO)"
	@echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files ..."
	$(RM) $(subst /,\,$(PRODUCT))
	$(RM) $(subst /,\,$(ALL_OBJS))
	$(RM) *Object
	$(ECHO) "### Deleted all derived files."



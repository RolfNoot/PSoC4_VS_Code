project('meson_test', 'c',
	version : '0.1',
	default_options : ['warning_level=3']
)

[host_machine]
system     = 'none'
cpu_family = 'arm'
cpu        = 'cortex-m0'
endian     = 'little'

#================================================================================================================================#
# check Creator_PostBuild version and set various variables for possible use

# Creator_PostBuild_Minumum_Version: '2.13' - used for checking Creator_PostBuild minimum version, do not remove

# Creator_PostBuild_Version_Line - automatic insert of Creator_PostBuild version. Do not edit the line below
creatorPostBuildVersion = '2.20'

# Creator_PostBuild_DateTime_Line - automatic insert of Creator Generated DateTime. Do not edit the line below
creatorGeneratedDateTime = '2024-08-14 14:02:15'

# Creator_PostBuild_devicePart_Line - automatic insert of device part by Creator_PostBuild. Do not edit the line below
devicePart = 'CY8C4248LQI-BL583'

# Creator_PostBuild_linkerFile_Line - automatic insert of linker file by Creator_PostBuild. Do not edit the line below
linkerFile = './Generated_Source/PSoC4/cm0gcc.ld'

# Creator_PostBuild_SVDfile_Line - automatic insert of SVD file by Creator_PostBuild. Do not edit the line below
SVDfile = 'PSoC_Creator.svd'

# Creator_PostBuild_prePostBuild_Lines - automatic insert of pre- and postbuild commands by Creator_PostBuild. Do not edit the two line below
preBuildCommands = ''
postBuildCommands = ''

# set directories
# Creator_PostBuild_Directory_Line - automatic insert of Creator Project main directory. Do not edit the line below
creatorDirectory = 'PSoC_Creator.cydsn'

# OTX_Extension_print(PROJECTNAME = '${workspaceFolderBasename}')
PROJECTNAME = 'PSoC4_VS_Code'

# OTX_Extension_print(ONETHINX_PACK_LOC = '${env:ONETHINX_PACK_LOC}')
ONETHINX_PACK_LOC = '/Applications/OTX-Maestro'

CONFIG_DIR 			= ONETHINX_PACK_LOC + '/config'
GCC_DIR 			= ONETHINX_PACK_LOC + '/gcc-arm/bin'
BIN_DIR 			= ONETHINX_PACK_LOC + '/bin'
SCRIPTS_DIR 		= ONETHINX_PACK_LOC + '/config/scripts'

MESON_SOURCE_LOC 	= meson.current_source_dir()
CREATOR_DIR 		= MESON_SOURCE_LOC + '/' + creatorDirectory

#================================================================================================================================#
# import tools

objcopy  		= find_program(GCC_DIR + '/arm-none-eabi-objcopy').path()
objdump  		= find_program(GCC_DIR + '/arm-none-eabi-objdump').path()
size     		= find_program(GCC_DIR + '/arm-none-eabi-size').path()
gdb      		= find_program(GCC_DIR + '/arm-none-eabi-gdb').path()
cymcuelftool 	= find_program(BIN_DIR + '/cymcuelftool').path()
readelf  		= find_program(GCC_DIR + '/arm-none-eabi-readelf').path()
memcalc 		= find_program(BIN_DIR + '/memcalc').path()
cyelftool       = find_program(BIN_DIR + '/cyelftool').path()

#================================================================================================================================#
# setup compile & link arguments

assembler_args = [
# Creator_PostBuild_AssemblerOptions_Start - automatic insert of assembler options by Creator_PostBuild. Do not edit below this line
	'-mcpu=cortex-m0',
	'-mthumb',
	'-g',
	'-W',
# Creator_PostBuild_AssemblerOptions_End - automatic insert of assembler options by Creator_PostBuild. Do not edit above this line
]

compiler_args     = [
# Creator_PostBuild_CompilerOptions_Start - automatic insert of compiler options by Creator_PostBuild. Do not edit below this line
	'-mcpu=cortex-m0',
	'-mthumb',
	'-g',
	'-DDEBUG',
	'-Wall',
	'-ffunction-sections',
	'-ffat-lto-objects',
	'-O0',
# Creator_PostBuild_CompilerOptions_End - automatic insert of compiler options by Creator_PostBuild. Do not edit above this line
]

linker_args     = [
# Creator_PostBuild_LinkerOptions_Start - automatic insert of linker options by Creator_PostBuild. Do not edit below this line
	'-mcpu=cortex-m0',
	'-mthumb',
	'-L'+CREATOR_DIR+'/Generated_Source/PSoC4',
	'-T'+CREATOR_DIR+'/Generated_Source/PSoC4/cm0gcc.ld',
	'-specs=nano.specs',
	'-Wl,--gc-sections',
	'-g',
	'-ffunction-sections',
	'-O0',
	'-ffat-lto-objects',
# Creator_PostBuild_LinkerOptions_End - automatic insert of linker options by Creator_PostBuild. Do not edit above this line
]

include_dirs       = [
# OTX_Extension_HeaderFiles_Start - automatic insert of source files by the OTX VSCode extension. Do not edit below this line
	'source',
# OTX_Extension_HeaderFiles_End - automatic insert of source files by the OTX VSCode extension. Do not edit above this line

# Creator_PostBuild_IncludeFolders_Start - automatic insert of include header folders by Creator_PostBuild. Do not edit below this line
	'PSoC_Creator.cydsn/',
	'PSoC_Creator.cydsn/Generated_Source/PSoC4',
# Creator_PostBuild_IncludeFolders_End - automatic insert of include header folders by Creator_PostBuild. Do not edit above this line
]

sourcefiles       = [
# manual insert of Creator_PostBuild stripped files

# OTX_Extension_SourceFiles_Start - automatic insert of source files by the OTX VSCode extension. Do not edit below this line
	'source/app_Ble.c',
	'source/app_LED.c',
	'source/app_UART.c',
	'source/main.c',
# OTX_Extension_SourceFiles_End - automatic insert of source files by the OTX VSCode extension. Do not edit above this line

# Creator_PostBuild_SourceFiles_Start - automatic insert of source files by Creator_PostBuild. Do not edit below this line
	'PSoC_Creator.cydsn/Generated_Source/PSoC4/cyfitter_cfg.c',
	'PSoC_Creator.cydsn/Generated_Source/PSoC4/cymetadata.c',
	'PSoC_Creator.cydsn/Generated_Source/PSoC4/BLE.c',
	'PSoC_Creator.cydsn/Generated_Source/PSoC4/BLE_gatt.c',
	'PSoC_Creator.cydsn/Generated_Source/PSoC4/BLE_eventHandler.c',
	'PSoC_Creator.cydsn/Generated_Source/PSoC4/BLE_HAL_INT.c',
	'PSoC_Creator.cydsn/Generated_Source/PSoC4/BLE_HAL_PVT.c',
	'PSoC_Creator.cydsn/Generated_Source/PSoC4/BLE_custom.c',
	'PSoC_Creator.cydsn/Generated_Source/PSoC4/Scan_LED.c',
	'PSoC_Creator.cydsn/Generated_Source/PSoC4/Scan_LED_PM.c',
	'PSoC_Creator.cydsn/Generated_Source/PSoC4/Conn_LED.c',
	'PSoC_Creator.cydsn/Generated_Source/PSoC4/Conn_LED_PM.c',
	'PSoC_Creator.cydsn/Generated_Source/PSoC4/UART.c',
	'PSoC_Creator.cydsn/Generated_Source/PSoC4/UART_SPI_UART.c',
	'PSoC_Creator.cydsn/Generated_Source/PSoC4/UART_SPI_UART_INT.c',
	'PSoC_Creator.cydsn/Generated_Source/PSoC4/UART_PM.c',
	'PSoC_Creator.cydsn/Generated_Source/PSoC4/UART_UART.c',
	'PSoC_Creator.cydsn/Generated_Source/PSoC4/UART_BOOT.c',
	'PSoC_Creator.cydsn/Generated_Source/PSoC4/UART_UART_BOOT.c',
	'PSoC_Creator.cydsn/Generated_Source/PSoC4/BLE_bless_isr.c',
	'PSoC_Creator.cydsn/Generated_Source/PSoC4/UART_SCBCLK.c',
	'PSoC_Creator.cydsn/Generated_Source/PSoC4/UART_tx.c',
	'PSoC_Creator.cydsn/Generated_Source/PSoC4/UART_tx_PM.c',
	'PSoC_Creator.cydsn/Generated_Source/PSoC4/UART_SCB_IRQ.c',
	'PSoC_Creator.cydsn/Generated_Source/PSoC4/UART_rx.c',
	'PSoC_Creator.cydsn/Generated_Source/PSoC4/UART_rx_PM.c',
	'PSoC_Creator.cydsn/Generated_Source/PSoC4/Cm0Start.c',
	'PSoC_Creator.cydsn/Generated_Source/PSoC4/CyFlash.c',
	'PSoC_Creator.cydsn/Generated_Source/PSoC4/CyLib.c',
	'PSoC_Creator.cydsn/Generated_Source/PSoC4/cyPm.c',
	'PSoC_Creator.cydsn/Generated_Source/PSoC4/cyutils.c',
	'PSoC_Creator.cydsn/Generated_Source/PSoC4/CyDMA.c',
	'PSoC_Creator.cydsn/Generated_Source/PSoC4/CyLFClk.c',
	'PSoC_Creator.cydsn/Generated_Source/PSoC4/cy_em_eeprom.c',
	'PSoC_Creator.cydsn/Generated_Source/PSoC4/Clock_1.c',
	'PSoC_Creator.cydsn/Generated_Source/PSoC4/P2_1.c',
	'PSoC_Creator.cydsn/Generated_Source/PSoC4/P2_1_PM.c',
	'PSoC_Creator.cydsn/Generated_Source/PSoC4/P2_3.c',
	'PSoC_Creator.cydsn/Generated_Source/PSoC4/P2_3_PM.c',
	'PSoC_Creator.cydsn/Generated_Source/PSoC4/P2_5.c',
	'PSoC_Creator.cydsn/Generated_Source/PSoC4/P2_5_PM.c',
	'PSoC_Creator.cydsn/Generated_Source/PSoC4/P2_7.c',
	'PSoC_Creator.cydsn/Generated_Source/PSoC4/P2_7_PM.c',
	'PSoC_Creator.cydsn/Generated_Source/PSoC4/P5_0.c',
	'PSoC_Creator.cydsn/Generated_Source/PSoC4/P5_0_PM.c',
	'PSoC_Creator.cydsn/Generated_Source/PSoC4/P5_1.c',
	'PSoC_Creator.cydsn/Generated_Source/PSoC4/P5_1_PM.c',
	'PSoC_Creator.cydsn/Generated_Source/PSoC4/P3_1.c',
	'PSoC_Creator.cydsn/Generated_Source/PSoC4/P3_1_PM.c',
	'PSoC_Creator.cydsn/Generated_Source/PSoC4/P3_3.c',
	'PSoC_Creator.cydsn/Generated_Source/PSoC4/P3_3_PM.c',
	'PSoC_Creator.cydsn/Generated_Source/PSoC4/Timer_1.c',
	'PSoC_Creator.cydsn/Generated_Source/PSoC4/Timer_1_PM.c',
	'PSoC_Creator.cydsn/Generated_Source/PSoC4/CyBootAsmGnu.s',
# Creator_PostBuild_SourceFiles_End - automatic insert of source files by Creator_PostBuild. Do not edit above this line
]

#================================================================================================================================#
# include libraries

cc = meson.get_compiler('c')

# example: include library.a from directory
#link_deps = declare_dependency( dependencies : cc.find_library('library', dirs : ['directory/libdir']) )

link_deps = [
# Creator_PostBuild_LibSources_Start - automatic insert of include source files by Creator_PostBuild. Do not edit below this line
	declare_dependency( dependencies : cc.find_library('gccCyBLEStack_BLE_SOC_CENTRAL', dirs : [CREATOR_DIR + '/']) ),
# Creator_PostBuild_LibSources_End - automatic insert of include source files by Creator_PostBuild. Do not edit above this line
]


#================================================================================================================================#
# run prebuild script 

#prebuild = custom_target('prebuild', output : 'buildversion.h', command : [MESON_SOURCE_LOC+'/config/prebuild.bash'])
#link_deps += declare_dependency( sources : [prebuild])

#================================================================================================================================#
# build executable

main = executable(
            PROJECTNAME,          [sourcefiles],
            name_suffix         : 'elf',
            c_args              : [compiler_args],
            link_args           : [linker_args],
            dependencies        : link_deps,
            include_directories : [include_dirs] )

#================================================================================================================================#
# create custom target : create binary, hex dump, size and disassemble dump

elfout = custom_target(
                        PROJECTNAME + '.elf',
    output           : [PROJECTNAME + '1.elf'],
    build_by_default : true,
    # command          : [cyelftool, '-C',  PROJECTNAME + '.elf', '--flash_row_size', '128', '--flash_size', '131072', '--flash_offset', '0x00000000'], # 128KB Flash
    command          : [cyelftool, '-C',  PROJECTNAME + '.elf', '--flash_row_size', '256', '--flash_size', '262144', '--flash_offset', '0x00000000'], # 256KB Flash
    depends          : [main])


mainout = custom_target(
                        PROJECTNAME + '.memcalc.txt',
    output           :  [PROJECTNAME + '.memcalc.txt'],
    build_by_default : true,
	console			 : true,
    # command          : [memcalc, readelf, PROJECTNAME + '.elf', '0x20000', '0x4000', '0x00000000', '0x1FFF8000', PROJECTNAME + '.memcalc.txt'],  # 128KB Flash
    command          : [memcalc, readelf, PROJECTNAME + '.elf', '0x40000', '0x8000', '0x00000000', '0x1FFF8000', PROJECTNAME + '.memcalc.txt'],  # 256KB Flash
    depends          : [elfout])


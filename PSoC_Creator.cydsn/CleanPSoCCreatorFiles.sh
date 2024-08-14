#!/bin/bash

# Change to the directory where the script is located
cd "$(dirname "$0")"

# Remove directories and their contents
rm -rf codegentemp
rm -rf CortexM0
rm -rf CortexM0p
rm -rf CortexM3
rm -rf CortexM4
#rm -rf Generated_Source
#rm -rf Export
rm -rf armgcc
rm -rf iar
rm -rf mdk

# Remove specific file types
rm -f *.rpt
rm -f *.cyfit
rm -f *.cycdx
rm -f *.html
rm -f *.svd
rm -f *.scat
#rm -f *.ld
rm -f *.icf
rm -f *.cyprj.*
rm -f *.cywrk.*
#rm -f *system_psoc63_cm*.c
#rm -f cy_ipc_config.*
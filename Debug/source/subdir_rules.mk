################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
source/key.obj: ../source/key.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_6.4.6/bin/cl2000" -v28 -ml -mt --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_6.4.6/include" --include_path="C:/ti/ccs_workspace/test/headers" --include_path="C:/ti/ccs_workspace/test/source" --include_path="C:/ti/controlSUITE/device_support/f2803x/v130/DSP2803x_common/include" --include_path="C:/ti/controlSUITE/device_support/f2803x/v130/DSP2803x_headers/include" --advice:performance=all -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="source/key.pp" --obj_directory="source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/led.obj: ../source/led.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_6.4.6/bin/cl2000" -v28 -ml -mt --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_6.4.6/include" --include_path="C:/ti/ccs_workspace/test/headers" --include_path="C:/ti/ccs_workspace/test/source" --include_path="C:/ti/controlSUITE/device_support/f2803x/v130/DSP2803x_common/include" --include_path="C:/ti/controlSUITE/device_support/f2803x/v130/DSP2803x_headers/include" --advice:performance=all -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="source/led.pp" --obj_directory="source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '



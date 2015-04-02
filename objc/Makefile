CFLAGS=-MMD -MP -DGNUSTEP -DGNUSTEP_BASE_LIBRARY=1 -DGNU_GUI_LIBRARY=1\
	   -DGNU_RUNTIME=1 -DGNUSTEP_BASE_LIBRARY=1 -fno-strict-aliasing\
	   -fexceptions -fobjc-exceptions -D_NATIVE_OBJC_EXCEPTIONS -pthread\
	   -fPIC -Wall -DGSWARN -DGSDIAGNOSE -Wno-import -g -O2 -fgnu-runtime\
	   -fconstant-string-class=NSConstantString -fexec-charset=UTF-8\
	   -I. -I/home/gongcheng/GNUstep/Library/Headers\
	   -I/usr/local/include/GNUstep -I/usr/include/GNUstep
LIBS=-rdynamic -pthread -shared-libgcc -fexceptions -fgnu-runtime \
	 -L/home/gongcheng/GNUstep/Library/Libraries -L/usr/local/lib \
	 -L/usr/lib -lgnustep-base -lobjc -lm
obj=hello.exe sizeof.exe variable.exe constant.exe const.exe max.exe number.exe\
	array.exe address.exe pointer.exe null_pointer.exe string_func.exe string.exe\
	struct.exe struct_func.exe struct_pointer.exe macro_predefined.exe macro_func.exe\
	macro_stringize.exe token_pasting.exe defined.exe typedef.exe define.exe cgfloat.exe\
	integer_promotion.exe debug_log.exe error_handling.exe argument.exe argument1.exe\

all.exe:$(obj)
%.exe:%.m
	gcc $(CFLAGS) -o $@ $< $(LIBS)
.PHONY:clean
clean:
	rm -f *.d
	rm -f *.exe

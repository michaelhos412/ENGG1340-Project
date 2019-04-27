AddRecord.o : AddRecord.cpp AddRecord.h structandglobals.h
	g++ -c $<
checkbudget.o : checkbudget.cpp checkbudget.h structandglobals.h
	g++ -c $<
checkdate.o : checkdate.cpp checkdate.h structandglobals.h
	g++ -c $<
EditRecord.o : EditRecord.cpp EditRecord.h structandglobals.h
	g++ -c $<
FilterbyAccount.o : FilterbyAccount.cpp FilterbyAccount.h structandglobals.h
	g++ -c $<
FilterbyCategory.o : FilterbyCategory.cpp FilterbyCategory.h structandglobals.h
	g++ -c $<
FilterbyType.o : FilterbyType.cpp FilterbyType.h structandglobals.h
	g++ -c $<
getall.o : getall.cpp getall.h structandglobals.h
	g++ -c $<
printingfunctions.o : printingfunctions.cpp printingfunctions.h structandglobals.h
	g++ -c $<
setbudget.o: setbudget.cpp setbudget.h structandglobals.h
	g++ -c $<
SortbyAmount.o : SortbyAmount.cpp SortbyAmount.h structandglobals.h
	g++ -c $<
main.o: main.cpp
	g++ -c $<
program: AddRecord.o checkbudget.o checkdate.o EditRecord.o FilterbyAccount.o FilterbyCategory.o FilterbyType.o getall.o printingfunctions.o setbudget.o SortbyAmount.o main.o
	g++ $^ -o $@

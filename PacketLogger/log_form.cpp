#include "log_form.h"


log_form::log_form()
{
	caption(STR("PacketLogger"));

	lb->append_header(STR("type"));
	lb->append_header(STR("ret addy"));
	lb->append_header(STR("size"));
	lb->append_header(STR("header"));
	lb->append_header(STR("formatted packet"));

	lb->at(0).append({STR("in"), STR("0x1337"), STR("20"), STR("0x0000"), STR("12 1234 12345678 \"test\" [1234567890]")});

	plc->div("<listbox margin=7>");
	plc->field("listbox") << lb->handle();
	plc->collocate();
}

log_form& log_form::instance()
{
	static log_form lf;
	return lf;
}

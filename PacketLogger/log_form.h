#pragma once
#include <nana/gui.hpp>
#include <nana/gui/place.hpp>
#include <nana/gui/widgets/listbox.hpp>

class log_form : public nana::form
{
	std::unique_ptr<nana::listbox> lb = std::make_unique<nana::listbox>(*this);
	std::unique_ptr<nana::place> plc = std::make_unique<nana::place>(*this);

	log_form();

public:
	static log_form& instance();
};

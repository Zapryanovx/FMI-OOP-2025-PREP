#pragma once
#include "Control.h"
#include "Option.h"

class RadioButton: public Control
{
public:
	RadioButton(const Size& size, const Location& location, const Option* options, size_t cnt);

	RadioButton(const RadioButton& other);
	RadioButton& operator=(const RadioButton& other);

	RadioButton(RadioButton&& other) noexcept;
	RadioButton& operator=(RadioButton&& other) noexcept; 

	~RadioButton();

	virtual void setDataDialog() override;
	virtual Control* clone() const override;

private:
	Option* options = nullptr;
	size_t cnt = 0;

	void initOptions(const Option* options, size_t cnt);

	void free();
	void copyFrom(const RadioButton& other);
	void moveFrom(RadioButton&& move);
};


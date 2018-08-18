/* === S Y N F I G ========================================================= */
/*!	\file widgets/widget_canvastimeslider.h
**	\brief Canvas Time Slider Widget Header
**
**	$Id$
**
**	\legal
**	......... ... 2018 Ivan Mahohnin
**
**	This package is free software; you can redistribute it and/or
**	modify it under the terms of the GNU General Public License as
**	published by the Free Software Foundation; either version 2 of
**	the License, or (at your option) any later version.
**
**	This package is distributed in the hope that it will be useful,
**	but WITHOUT ANY WARRANTY; without even the implied warranty of
**	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
**	General Public License for more details.
**	\endlegal
*/
/* ========================================================================= */

/* === S T A R T =========================================================== */

#ifndef __SYNFIG_WIDGET_CANVASTIMESLIDER_H
#define __SYNFIG_WIDGET_CANVASTIMESLIDER_H

/* === H E A D E R S ======================================================= */

#include <gtkmm/image.h>

#include "widget_timeslider.h"

/* === M A C R O S ========================================================= */

/* === T Y P E D E F S ===================================================== */

/* === C L A S S E S & S T R U C T S ======================================= */

namespace studio {

class CanvasView;

class Widget_CanvasTimeslider : public Widget_Timeslider
{
protected:
	sigc::connection rendering_change;
	etl::loose_handle<CanvasView> canvas_view;
	Gtk::Window tooltip;
	Gtk::Image thumb;

	virtual void draw_background(const Cairo::RefPtr<Cairo::Context> &cr);

	virtual bool on_motion_notify_event(GdkEventMotion* event);
	virtual bool on_leave_notify_event(GdkEventCrossing* event);

public:
	Widget_CanvasTimeslider();
	~Widget_CanvasTimeslider();

	const etl::loose_handle<CanvasView>& get_canvas_view() const { return canvas_view; }
	void set_canvas_view(const etl::loose_handle<CanvasView> &x);
};

}; // END of namespace studio

/* === E N D =============================================================== */

#endif

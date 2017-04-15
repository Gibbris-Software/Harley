using System;
using Gtk;

namespace Harley
{
	public interface ISituation
	{
		void Redraw(Cairo.Context cr, Player player);
	}
}


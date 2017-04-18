using System;
using Gtk;

namespace Harley
{
	public interface ISituation
	{
		void Redraw(Cairo.Context cr);
		void StartLeft();
		void StartRight();
		void StartUp();
		void StartDown();
		void StopLeft();
		void StopRight();
		void StopUp();
		void StopDown();
		void Update();
	}
}


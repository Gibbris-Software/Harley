using System;
using Gtk;

namespace Harley
{
	public class Battle : ISituation
	{
		public Battle ()
		{
		}

		public void Redraw(Cairo.Context cr, Player player)
		{
			cr.SetSourceRGB (0.25, 0.75, 0.0);

			cr.Paint ();

			cr.Arc (player.BattleX * 16 + 8, player.BattleY * 16 + 8, 8, 0, Math.PI * 2);

			cr.SetSourceRGB (0.1, 0.2, 0.75);
			cr.Fill ();

			((IDisposable) cr.GetTarget()).Dispose();
			((IDisposable) cr).Dispose();
		}
	}
}


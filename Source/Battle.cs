using System;
using Gtk;

namespace Harley
{
	public class Battle : ISituation
	{
		private Tileset Tiles;
		private Map Map;

		public Battle ()
		{
			Tiles = new Tileset ("Resources/anais.png");
			Map = new Map ("Resources/anais.map");
		}

		public void Redraw(Cairo.Context cr, Player player)
		{
			//cr.Scale (2, 2);
			cr.Antialias = Cairo.Antialias.None;

			for (int i = 0; i < 20; i++) {
				for (int j = 0; j < 15; j++) {
					Tile tile = Tiles.Tile (Map.Tile (i, j));
					cr.Rectangle (i * 16, j * 16, 16, 16);
					cr.SetSourceSurface(tile.Surface, i*16, j*16);
					cr.Fill ();
				}
			}

			cr.Arc (player.BattleX * 16 + 8, player.BattleY * 16 + 8, 8, 0, Math.PI * 2);

			cr.SetSourceRGB (0.1, 0.2, 0.75);
			cr.Fill ();

			((IDisposable) cr.GetTarget()).Dispose();
			((IDisposable) cr).Dispose();
		}
	}
}


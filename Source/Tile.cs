using System;
using System.Collections.Generic;

namespace Harley
{
	public class Tile
	{
		private Cairo.Surface tile;
		public Tile(Cairo.Surface surface, int x, int y)
		{
			tile = new Cairo.ImageSurface (Cairo.Format.ARGB32, 16, 16);
			Cairo.Context cr = new Cairo.Context (tile);
			cr.Translate (-x * 16, -y * 16);
			cr.Antialias = Cairo.Antialias.None;
			cr.SetSourceSurface (surface, 0, 0);

			cr.Paint ();
		}

		public Cairo.Surface Surface {
			get { return tile; }
		}
	}

	public class Tileset
	{
		private List<Tile> tiles;
		public Tileset (string location)
		{
			Cairo.ImageSurface surface = new Cairo.ImageSurface (location);
			int width = surface.Width / 16;
			int height = surface.Height / 16;
			tiles = new List<Tile> ();
			for (int i = 0; i < width; i++) {
				for (int j = 0; j < height; j++) {
					tiles.Add (new Tile (surface, i, j));
				}
			}
		}

		public Tile Tile(int which){
			return tiles[which];
		}
	}
}


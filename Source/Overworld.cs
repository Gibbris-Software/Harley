using System;

namespace Harley
{
	public class Overworld : ISituation
	{
		private Tileset tiles;
		private Map map;
		private Player character;

		private bool movingRight;
		private bool movingLeft;
		private bool movingUp;
		private bool movingDown;

		private int speed;

		public Overworld (Player player)
		{
			tiles = new Tileset ("Resources/anais.png");
			map = new Map ("Resources/anais.map");
			character = player;
			movingRight = false;
			movingUp = false;
			movingLeft = false;
			movingDown = false;
			speed = 3;
		}

		public void Redraw(Cairo.Context cr)
		{
			//cr.Scale (2, 2);
			cr.Antialias = Cairo.Antialias.None;

			for (int i = 0; i < 20; i++) {
				for (int j = 0; j < 15; j++) {
					Tile tile = tiles.Tile (map.Tile (i, j));
					cr.Rectangle (i * 16, j * 16, 16, 16);
					cr.SetSourceSurface(tile.Surface, i*16, j*16);
					cr.Fill ();
				}
			}

			cr.Arc (character.TileX, character.TileY, 8, 0, Math.PI * 2);

			cr.SetSourceRGB (0.1, 0.2, 0.75);
			cr.Fill ();

			((IDisposable) cr.GetTarget()).Dispose();
			((IDisposable) cr).Dispose();
		}

		public void StartUp(){
			movingUp = true;
			movingDown = false;
			if (movingLeft || movingRight) {
				speed = 2;
			}
		}

		public void StartDown(){
			movingDown = true;
			movingUp = false;
			if (movingLeft || movingRight) {
				speed = 2;
			}
		}

		public void StartLeft(){
			movingLeft = true;
			movingRight = false;
			if (movingUp || movingDown) {
				speed = 2;
			}
		}

		public void StartRight ()
		{
			movingRight = true;
			movingLeft = false;
			if (movingUp || movingDown) {
				speed = 2;
			}
		}

		public void StopUp(){
			movingUp = false;
			speed = 3;
		}

		public void StopDown(){
			movingDown = false;
			speed = 3;
		}

		public void StopLeft(){
			movingLeft = false;
			speed = 3;
		}

		public void StopRight ()
		{
			movingRight = false;
			speed = 3;
		}

		public void Update(){
			if (movingUp) {
				character.MoveUpTile (speed);
			} else if (movingDown) {
				character.MoveDownTile (speed);
			}

			if (movingRight) {
				character.MoveRightTile (speed);
			} else if (movingLeft) {
				character.MoveLeftTile (speed);
			}
		}
	}
}


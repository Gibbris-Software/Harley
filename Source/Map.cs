using System;
using System.IO;
using System.Collections.Generic;

namespace Harley
{
	public class Map
	{
		private List<List<int>> tiles;

		public Map (string filename)
		{
			List<string[]> indices = new List<string[]>();
			using (StreamReader mapData = new StreamReader(filename)) {
				do {
					string line = mapData.ReadLine ();
					indices.Add(line.Split(new String[] {","}, StringSplitOptions.None));
				} while (mapData.Peek () != -1);
			}
			tiles = new List<List<int>>();
			for (int i = 0; i < indices.Count; i++) {
				List<int> row = new List<int> ();
				for (int j = 0; j < indices[0].GetLength(0); j++) {
					row.Add(int.Parse (indices [i] [j]));
				}
				tiles.Add (row);
			}
		}

		public int Tile(int x, int y){
			return tiles[y][x];
		}
	}
}

